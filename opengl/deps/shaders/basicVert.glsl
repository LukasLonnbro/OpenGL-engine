#version 330
layout(location=0) in vec3 pos;
layout(location=1) in vec3 normal;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

void main()
{
    vec4 position = vec4(pos, 1.0f);
    gl_Position = projection * view * model * position;
}
