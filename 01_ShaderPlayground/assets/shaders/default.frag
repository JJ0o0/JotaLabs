#version 410 core
out vec4 FragPos;
in vec3 Normal;
in vec2 TexCoord;

uniform vec3 uColor;
uniform float uIntensity;

void main() {
    FragPos = vec4(uColor * uIntensity, 1.0);
}