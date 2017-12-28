#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

out vec3 Normal;
out vec3 FragPos;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 modelOnlyRotation;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
//    Normal = aNormal;

    // this are two ways of takeout translation from the model matrix
    Normal = mat3(model) * aNormal;
//    Normal = vec3(modelOnlyRotation * vec4(aNormal, 1.0));


    // Fragments should contain translation data
     FragPos = vec3(model * vec4(aPos, 1.0));
//    FragPos = vec3(modelOnlyRotation * vec4(aPos, 1.0));

    TexCoord = aTexCoord;

}
