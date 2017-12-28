//
// Created by Nando on 12/25/17.
//

#ifndef COMPUTERGRAPHICSBASEPROJECT_MATERIALS_H
#define COMPUTERGRAPHICSBASEPROJECT_MATERIALS_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Materials {

	struct Material {
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;
		float shininess;
		glm::vec3 color;
	};

	Material extern Gold;

	Material extern Silver;

	Material extern Obsidian;

	Material extern Ruby;

	Material extern Turquoise;

	Material extern materials[5];

}

#endif //COMPUTERGRAPHICSBASEPROJECT_MATERIALS_H
