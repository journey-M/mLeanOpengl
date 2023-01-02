#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D textureY;
uniform sampler2D textureU;
uniform sampler2D textureV;
varying vec2 _outUV;

void main(){
  
  vec3 yuv;
  vec3 rgb;

  yuv.x = texture(textureY , TexCoord).a;
  yuv.y = texture(textureU , TexCoord).a -0.5;
  yuv.z = texture(textureV , TexCoord).a - 0.5;
  rgb = mat3(1.0,     1.0,        1.0,
             0.0,     -0.39465, 2.03210,
             1.13983,-0.58060, 0.0) *yuv;

	FragColor = (yuv, 1.0);
}
