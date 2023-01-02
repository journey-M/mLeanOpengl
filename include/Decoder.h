#ifndef __DECODER_H__
#define __DECODER_H__

#include "./IOperator.h"
#include "stb_image.h"
#include "Shader.h"
#include <stack>

extern "C"{
#include <libavutil/imgutils.h>
#include <libavutil/samplefmt.h>
#include <libavutil/timestamp.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
}


class Decoder{
	private:

   
    bool writeNative = false;

   AVFormatContext *fmt_ctx = NULL;
   AVCodecContext *video_dec_ctx = NULL, *audio_dec_ctx;
   enum AVPixelFormat pix_fmt;
   AVStream *video_stream = NULL, *audio_stream = NULL;
   const char *src_filename = NULL;
   const char *video_dst_filename = NULL;
   const char *audio_dst_filename = NULL;
   FILE *video_dst_file = NULL;
   FILE *audio_dst_file = NULL;

   uint8_t *video_dst_data[4] = {NULL};
   int      video_dst_linesize[4];
   int video_dst_bufsize;

   int video_stream_idx = -1, audio_stream_idx = -1;
   AVFrame *frame = NULL;
   AVPacket *pkt = NULL;
   int video_frame_count = 0;
   int audio_frame_count = 0;

	public:
    std::stack<uint8_t*> decodyuv; 
    std::stack<uint8_t*> decodrgb; 
    int width, height;



		void init(const char* vfile, const char* audioFile, const char* videoFile);

    void destroy();

    static void startDecode(Decoder *decoder);

    int  open_codec_context(int *stream_idx,
                              AVCodecContext **dec_ctx, AVFormatContext *fmt_ctx, enum AVMediaType type);

    int  decode_packet(AVCodecContext *dec, const AVPacket *pkt);

    int  get_format_from_sample_fmt(const char **fmt,
                                      enum AVSampleFormat sample_fmt);

    int output_audio_frame(AVFrame *frame);

    int output_video_frame(AVFrame *frame);



};

#endif
