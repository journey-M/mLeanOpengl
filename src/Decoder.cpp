#include "../include/Decoder.h"
#include <thread>

char averrStr[AV_ERROR_MAX_STRING_SIZE] = {0};

/**
 * Convenience macro, the return value should be used only directly in
 * function arguments but never stand-alone.
 */
#define av_err2str_my(errnum) \
    av_make_error_string(averrStr, AV_ERROR_MAX_STRING_SIZE, errnum)


#define av_ts2timestr_my(ts, tb) av_ts_make_time_string(averrStr, ts, tb)



//平面YUV420转RGB24
static void YUV420p_to_RGB24(unsigned char *yuv420[3], unsigned char *rgb24, int width, int height)
{
  // int begin = GetTickCount();
  int R,G,B,Y,U,V;
  int x,y;
  int nWidth = width>>1; //色度信号宽度
  for (y=0;y<height;y++)
  {
    for (x=0;x<width;x++)
    {
    Y = *(yuv420[0] + y*width + x);
    U = *(yuv420[1] + ((y>>1)*nWidth) + (x>>1));
    V = *(yuv420[2] + ((y>>1)*nWidth) + (x>>1));
    R = Y + 1.402*(V-128);
    G = Y - 0.34414*(U-128) - 0.71414*(V-128);
    B = Y + 1.772*(U-128);

    //防止越界
    if (R>255)R=255;
    if (R<0)R=0;
    if (G>255)G=255;
    if (G<0)G=0;
    if (B>255)B=255;
    if (B<0)B=0;

    *(rgb24 + ((height-y-1)*width + x)*3) = B;
    *(rgb24 + ((height-y-1)*width + x)*3 + 1) = G;
    *(rgb24 + ((height-y-1)*width + x)*3 + 2) = R;
    // *(rgb24 + (y*width + x)*3) = B;
    // *(rgb24 + (y*width + x)*3 + 1) = G;
    // *(rgb24 + (y*width + x)*3 + 2) = R; 
    }
  }
}


int Decoder::output_video_frame(AVFrame *frame)
{
    if (frame->width != width || frame->height != height ||
        frame->format != pix_fmt) {
        /* To handle this change, one could call av_image_alloc again and
         * decode the following frames into another rawvideo file. */
        fprintf(stderr, "Error: Width, height and pixel format have to be "
                "constant in a rawvideo file, but the width, height or "
                "pixel format of the input video changed:\n"
                "old: width = %d, height = %d, format = %s\n"
                "new: width = %d, height = %d, format = %s\n",
                width, height, av_get_pix_fmt_name(pix_fmt),
                frame->width, frame->height,
                av_get_pix_fmt_name((AVPixelFormat)frame->format));
        return -1;
    }

    // printf("video_frame n:%d coded_n:%d\n",
    //        video_frame_count++, frame->coded_picture_number);

    /* copy decoded frame to destination buffer:
     * this is required since rawvideo expects non aligned data */
    av_image_copy(video_dst_data, video_dst_linesize,
                  (const uint8_t **)(frame->data), frame->linesize,
                  pix_fmt, width, height);

    /* write to rawvideo file */
    if(writeNative) 
      fwrite(video_dst_data[0], 1, video_dst_bufsize, video_dst_file);

    // 转换吗后的rgb
    if(decodrgb.size() > 2){
      std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }
    //解码rgb数据
    // uint8_t * dataRgb = (uint8_t*) malloc( width * height * 3);
    // YUV420p_to_RGB24(video_dst_data, dataRgb, width, height);
    // decodrgb.push(dataRgb) ;

    //解码rgb数据
    if(decodyuv.size() > 2){
      std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }
    uint8_t * dataYuv = (uint8_t*) malloc( width * height * 3);
    memcpy(dataYuv, video_dst_data[0], video_dst_bufsize);

    decodyuv.push(dataYuv) ;



    return 0;
}

 int Decoder::output_audio_frame(AVFrame *frame)
{
    size_t unpadded_linesize = frame->nb_samples * av_get_bytes_per_sample((AVSampleFormat)frame->format);
    // printf("audio_frame n:%d nb_samples:%d pts:%s\n",
    //        audio_frame_count++, frame->nb_samples,
    //        av_ts2timestr(frame->pts, &audio_dec_ctx->time_base));

    /* Write the raw audio data samples of the first plane. This works
     * fine for packed formats (e.g. AV_SAMPLE_FMT_S16). However,
     * most audio decoders output planar audio, which uses a separate
     * plane of audio samples for each channel (e.g. AV_SAMPLE_FMT_S16P).
     * In other words, this code will write only the first audio channel
     * in these cases.
     * You should use libswresample or libavfilter to convert the frame
     * to packed data. */
    if(writeNative)
      fwrite(frame->extended_data[0], 1, unpadded_linesize, audio_dst_file);

    return 0;
}

 int  Decoder::decode_packet(AVCodecContext *dec, const AVPacket *pkt)
{
    int ret = 0;

    // submit the packet to the decoder
    ret = avcodec_send_packet(dec, pkt);
    if (ret < 0) {
        fprintf(stderr, "Error submitting a packet for decoding (%s)\n", av_err2str_my(ret));
        return ret;
    }

    // get all the available frames from the decoder
    while (ret >= 0) {
        ret = avcodec_receive_frame(dec, frame);
        if (ret < 0) {
            // those two return values are special and mean there is no output
            // frame available, but there were no errors during decoding
            if (ret == AVERROR_EOF || ret == AVERROR(EAGAIN))
                return 0;

            fprintf(stderr, "Error during decoding (%s)\n", av_err2str_my(ret));
            return ret;
        }

        // write the frame data to output file
        if (dec->codec->type == AVMEDIA_TYPE_VIDEO)
            ret = output_video_frame(frame);
        else
            ret = output_audio_frame(frame);

        av_frame_unref(frame);
        if (ret < 0)
            return ret;
    }

    return 0;
}

 int  Decoder::open_codec_context(int *stream_idx,
                              AVCodecContext **dec_ctx, AVFormatContext *fmt_ctx, enum AVMediaType type)
{
    int ret, stream_index;
    AVStream *st;
    const AVCodec *dec = NULL;
    AVDictionary *opts = NULL;

    ret = av_find_best_stream(fmt_ctx, type, -1, -1, NULL, 0);
    if (ret < 0) {
        fprintf(stderr, "Could not find %s stream in input file '%s'\n",
                av_get_media_type_string(type), src_filename);
        return ret;
    } else {
        stream_index = ret;
        st = fmt_ctx->streams[stream_index];

        /* find decoder for the stream */
        dec = avcodec_find_decoder(st->codecpar->codec_id);
        if (!dec) {
            fprintf(stderr, "Failed to find %s codec\n",
                    av_get_media_type_string(type));
            return AVERROR(EINVAL);
        }

        /* Allocate a codec context for the decoder */
        *dec_ctx = avcodec_alloc_context3(dec);
        if (!*dec_ctx) {
            fprintf(stderr, "Failed to allocate the %s codec context\n",
                    av_get_media_type_string(type));
            return AVERROR(ENOMEM);
        }

        /* Copy codec parameters from input stream to output codec context */
        if ((ret = avcodec_parameters_to_context(*dec_ctx, st->codecpar)) < 0) {
            fprintf(stderr, "Failed to copy %s codec parameters to decoder context\n",
                    av_get_media_type_string(type));
            return ret;
        }

        /* Init the decoders */
        if ((ret = avcodec_open2(*dec_ctx, dec, &opts)) < 0) {
            fprintf(stderr, "Failed to open %s codec\n",
                    av_get_media_type_string(type));
            return ret;
        }
        *stream_idx = stream_index;
    }

    return 0;
}

 int  Decoder::get_format_from_sample_fmt(const char **fmt,
                                      enum AVSampleFormat sample_fmt)
{
    int i;
    struct sample_fmt_entry {
        enum AVSampleFormat sample_fmt; const char *fmt_be, *fmt_le;
    } sample_fmt_entries[] = {
        { AV_SAMPLE_FMT_U8,  "u8",    "u8"    },
        { AV_SAMPLE_FMT_S16, "s16be", "s16le" },
        { AV_SAMPLE_FMT_S32, "s32be", "s32le" },
        { AV_SAMPLE_FMT_FLT, "f32be", "f32le" },
        { AV_SAMPLE_FMT_DBL, "f64be", "f64le" },
    };
    *fmt = NULL;

    for (i = 0; i < FF_ARRAY_ELEMS(sample_fmt_entries); i++) {
        struct sample_fmt_entry *entry = &sample_fmt_entries[i];
        if (sample_fmt == entry->sample_fmt) {
            *fmt = AV_NE(entry->fmt_be, entry->fmt_le);
            return 0;
        }
    }

    fprintf(stderr,
            "sample format %s is not supported as output format\n",
            av_get_sample_fmt_name(sample_fmt));
    return -1;
}

void Decoder::init(const char* fname ,const char * videoFname, const char* afileName)
{
    int ret = 0;
    src_filename = fname;
    video_dst_filename = videoFname;
    audio_dst_filename = afileName;

    /* open input file, and allocate format context */
    if (avformat_open_input(&fmt_ctx, src_filename, NULL, NULL) < 0) {
        fprintf(stderr, "Could not open source file %s\n", src_filename);
        exit(1);
    }

    /* retrieve stream information */
    if (avformat_find_stream_info(fmt_ctx, NULL) < 0) {
        fprintf(stderr, "Could not find stream information\n");
        exit(1);
    }

    if (open_codec_context(&video_stream_idx, &video_dec_ctx, fmt_ctx, AVMEDIA_TYPE_VIDEO) >= 0) {
        video_stream = fmt_ctx->streams[video_stream_idx];

        video_dst_file = fopen(video_dst_filename, "wb");
        if (!video_dst_file) {
            fprintf(stderr, "Could not open destination file %s\n", video_dst_filename);
            ret = 1;
            return;
        }

        /* allocate image where the decoded image will be put */
        width = video_dec_ctx->width;
        height = video_dec_ctx->height;
        pix_fmt = video_dec_ctx->pix_fmt;
        ret = av_image_alloc(video_dst_data, video_dst_linesize,
                             width, height, pix_fmt, 1);
        if (ret < 0) {
            fprintf(stderr, "Could not allocate raw video buffer\n");
            return ;
        }
        video_dst_bufsize = ret;
    }

    if (open_codec_context(&audio_stream_idx, &audio_dec_ctx, fmt_ctx, AVMEDIA_TYPE_AUDIO) >= 0) {
        audio_stream = fmt_ctx->streams[audio_stream_idx];
        audio_dst_file = fopen(audio_dst_filename, "wb");
        if (!audio_dst_file) {
            fprintf(stderr, "Could not open destination file %s\n", audio_dst_filename);
            ret = 1;
            return ;
        }
    }

    /* dump input information to stderr */
    av_dump_format(fmt_ctx, 0, src_filename, 0);

    if (!audio_stream && !video_stream) {
        fprintf(stderr, "Could not find audio or video stream in the input, aborting\n");
        ret = 1;
        return; 
    }

    frame = av_frame_alloc();
    if (!frame) {
        fprintf(stderr, "Could not allocate frame\n");
        ret = AVERROR(ENOMEM);
        return ;
    }

    pkt = av_packet_alloc();
    if (!pkt) {
        fprintf(stderr, "Could not allocate packet\n");
        ret = AVERROR(ENOMEM);
        return ;
    }

    if (video_stream)
        printf("Demuxing video from file '%s' into '%s'\n", src_filename, video_dst_filename);
    if (audio_stream)
        printf("Demuxing audio from file '%s' into '%s'\n", src_filename, audio_dst_filename);


}

 void Decoder::startDecode(Decoder * decoder){
  int ret=0;
    /* read frames from the file */
    while (av_read_frame(decoder->fmt_ctx, decoder->pkt) >= 0) {
        // check if the packet belongs to a stream we are interested in, otherwise
        // skip it
        if (decoder->pkt->stream_index == decoder->video_stream_idx)
            ret = decoder->decode_packet(decoder->video_dec_ctx, decoder->pkt);
        else if (decoder->pkt->stream_index == decoder->audio_stream_idx)
            ret =decoder->decode_packet(decoder->audio_dec_ctx, decoder->pkt);
        av_packet_unref(decoder->pkt);
        if (ret < 0)
            break;
    }

    /* flush the decoders */
    if (decoder->video_dec_ctx)
        decoder->decode_packet(decoder->video_dec_ctx, NULL);
    if (decoder->audio_dec_ctx)
        decoder->decode_packet(decoder->audio_dec_ctx, NULL);

    printf("Demuxing succeeded.\n");

    if (decoder->video_stream) {
        printf("Play the output video file with the command:\n"
               "ffplay -f rawvideo -pix_fmt %s -video_size %dx%d %s\n",
               av_get_pix_fmt_name(decoder->pix_fmt), decoder->width, decoder->height,
               decoder->video_dst_filename);
    }

    if (decoder->audio_stream) {
        enum AVSampleFormat sfmt = decoder->audio_dec_ctx->sample_fmt;
        int n_channels = decoder->audio_dec_ctx->channels;
        const char *fmt;

        if (av_sample_fmt_is_planar(sfmt)) {
            const char *packed = av_get_sample_fmt_name(sfmt);
            printf("Warning: the sample format the decoder produced is planar "
                   "(%s). This example will output the first channel only.\n",
                   packed ? packed : "?");
            sfmt = av_get_packed_sample_fmt(sfmt);
            n_channels = 1;
        }

        if ((ret = decoder->get_format_from_sample_fmt(&fmt, sfmt)) < 0)
            return ;

        printf("Play the output audio file with the command:\n"
               "ffplay -f %s -ac %d -ar %d %s\n",
               fmt, n_channels, decoder->audio_dec_ctx->sample_rate,
               decoder->audio_dst_filename);
    }

}


void Decoder::destroy(){
    avcodec_free_context(&video_dec_ctx);
    avcodec_free_context(&audio_dec_ctx);
    avformat_close_input(&fmt_ctx);
    if (video_dst_file)
        fclose(video_dst_file);
    if (audio_dst_file)
        fclose(audio_dst_file);
    av_packet_free(&pkt);
    av_frame_free(&frame);
    av_free(video_dst_data[0]);

}
