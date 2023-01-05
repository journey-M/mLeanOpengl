#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texturey;
uniform sampler2D textureu;
uniform sampler2D texturev;

varying vec2 _outUV;

void main(){
  
  vec3 yuv;
  vec3 rgb;

  yuv.x = texture2D(texturey , TexCoord).r;
  yuv.y = texture2D(textureu , TexCoord).r -0.5;
  yuv.z = texture2D(texturev , TexCoord).r- 0.5;
  rgb = mat3(1.0,     1.0,        1.0,
             0.0,     -0.39465, 2.03210,
             1.13983,-0.58060, 0.0) *yuv;

	FragColor = vec4(rgb, 1.0);
}
