//
// Created by Nando on 12/26/17.
//

#include "Materials.h"

//namespace Materials {

namespace Materials {

	Material Gold = Materials::Material{
		Gold.ambient = glm::vec3(0.24725f, 0.1995f, 0.0745f),
		Gold.diffuse = glm::vec3(0.75164f, 0.60648f, 0.22648f),
		Gold.specular = glm::vec3(0.628281f, 0.555802f, 0.366065f),
		Gold.shininess = 32.0f,
		Gold.color = glm::vec3(1.0f, 0.84313f, 0)
	};

	Material Silver = Material{
		Silver.ambient = glm::vec3(0.19225f, 0.19225f, 0.19225f),
		Silver.diffuse = glm::vec3(0.50754f, 0.50754f, 0.50754f),
		Silver.specular = glm::vec3(0.508273f, 0.508273f, 0.508273f),
		Silver.shininess = 32.0f,
		Silver.color = glm::vec3(0.75294f, 0.75294f, 0.75294f)
	};

	Material Obsidian = Material{
		Obsidian.ambient = glm::vec3(0.05375f, 0.05f, 0.06625f),
		Obsidian.diffuse = glm::vec3(0.18275f, 0.17f, 0.22525f),
		Obsidian.specular = glm::vec3(0.332741f, 0.328634f, 0.346435f),
		Obsidian.shininess = 512.0f,
		Obsidian.color = glm::vec3(0.20392f, 0.211764f, 0.21568f)
	};

	Material Ruby = Material{
		Ruby.ambient = glm::vec3(0.1745f, 0.01175f, 0.01175f),
		Ruby.diffuse = glm::vec3(0.61424f, 0.04136f, 0.04136f),
		Ruby.specular = glm::vec3(0.727811f, 0.626959f, 0.626959f),
		Ruby.shininess = 56.0f,
		Ruby.color = glm::vec3(0.60784f, 0.06666f, 0.11764f)
	};

	Material Turquoise = Material{
		Turquoise.ambient = glm::vec3(0.1f, 0.18725f, 0.1745f),
		Turquoise.diffuse = glm::vec3(0.396f, 0.74151f, 0.69102f),
		Turquoise.specular = glm::vec3(0.00392f, 0.99215f, 0.91372f),
		Turquoise.shininess = 16.0f
	};

	Material materials[5] = { Gold, Silver, Obsidian, Ruby, Turquoise };
}



//}

