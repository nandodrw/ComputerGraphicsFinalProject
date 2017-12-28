#version 330
out vec4 FragColor;
in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;

    vec3 color;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float texMixFactor;


uniform Material material;

uniform vec3 ObjectColor;
uniform vec3 LightColor;
uniform vec3 LightPos;
uniform vec3 viewPos;

#define NUM_LIGHTS 3

uniform Light lights[NUM_LIGHTS];


vec3 CalcLight(Light light, vec3 normalCollection, vec3 fragPos) {
        // ambient light
        vec3 ambient = light.ambient * material.ambient;

        // diffuse lighting
        vec3 normal = normalize(normalCollection);
        vec3 lightDir = normalize(light.position - fragPos);
        float diff = max(dot(normal, lightDir), 0.0);
        // float diff = dot(normal, lightPos);
        vec3 diffuse = diff * material.diffuse * light.diffuse;

        //    specular lighting
        vec3 viewDirection = normalize(viewPos - fragPos);
        vec3 reflectDir = reflect(-lightDir, normal);
        float spec = pow(max(dot(viewDirection, reflectDir), 0.0), material.shininess);
        vec3 specular = (material.specular * spec) * light.specular;

        return (diffuse + ambient + specular);

}

void main() {

    vec3 result = vec3(0.0);

    vec4 textureMix = mix(texture(texture1, TexCoord), texture(texture2, vec2(-1.0 * TexCoord.x, TexCoord.y)), texMixFactor);

    for(int i = 0; i < NUM_LIGHTS; i++) {
        result += CalcLight(lights[i], Normal, FragPos);
    }

//    FragColor = vec4(result, 1.0);

//    FragColor = textureMix;

    gl_FragColor = vec4(result, 1.0) * textureMix;
}
