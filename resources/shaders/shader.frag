#version 330 core

in vec2 textureCoordinates;

out vec4 color;

uniform sampler2D image;

void main() {
    color = texture(image, textureCoordinates);
}
