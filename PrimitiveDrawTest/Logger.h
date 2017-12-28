//
// Created by Nando on 12/25/17.
//

#ifndef COMPUTERGRAPHICSBASEPROJECT_LOGGER_H
#define COMPUTERGRAPHICSBASEPROJECT_LOGGER_H

#include <iostream>
#include <string>

class Logger {

public:
	static void log(std::string message) {
		std::cout << message << std::endl;
	}
};


#endif //COMPUTERGRAPHICSBASEPROJECT_LOGGER_H
