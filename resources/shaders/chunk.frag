#version 330 core

in vec2 textureCoordinates;
in float brightness;

out vec4 color;

uniform sampler2D image;

void main() {
    color = brightness * texture(image, textureCoordinates);
}
