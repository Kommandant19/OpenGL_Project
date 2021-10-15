#version 330 core

layout(location = 0) out vec4 FragColor;

uniform vec4 u_Color; // we set this variable in the OpenGL code.

void main()
{
    FragColor = u_Color;
}