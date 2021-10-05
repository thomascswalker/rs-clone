#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    float gamma = 2.2;
    ourColor = pow(aColor, vec3(1.0/gamma));
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}