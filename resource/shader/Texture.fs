#version 410 core

in vec2 TexCoord;
uniform sampler2D outTexture;

out vec4 FragColor;

void main () {
    vec4 texColor = texture(outTexture, TexCoord);
    if(texColor.a < 0.1)
        discard;
    FragColor = texColor;
}
