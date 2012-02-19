/* 
 * File:   main.cpp
 * Author: paul
 * Purpose: Produce fixture file *fixture.yaml* with input-output mapping for prime-finder library
 * Created on February 18, 2012, 12:01 AM
 */

#include <iostream>
#include <fstream>
#include "../prime-finder/Finder.h"

#include <yaml-cpp/yaml.h>

 #define START_POS 10000
 #define END_POS 10
 #define STEP 100

 #define OUTPUT_FILE_PATH "./fixture.yaml"

 int main ( int argc, char ** argv )
 {
 	PrimeFinder::Finder finder;

 	YAML::Emitter yemt;

 	std::ofstream file;

 	yemt << YAML::BeginSeq;

 	std::cout << "[ OK ] Start producing fixture." << std::endl;

 	for ( unsigned int i = START_POS; i >= END_POS; i -= STEP )
 	{
 		std::cout << "[ OK ] Step" << std::endl;

 		long result = finder.find(i);

 		yemt << YAML::BeginMap;

 		yemt << YAML::Key << "input";

 		yemt << YAML::Value << i;

 		yemt << YAML::Key << "output";

 		yemt << YAML::Value << result;

 		yemt << YAML::EndMap;
 	}

 	std::cout << "[ OK ] Producing successfully finished." << std::endl;

 	yemt << YAML::EndSeq;

 	file.open(OUTPUT_FILE_PATH);

 	file << yemt.c_str();

 	file.close();

 	return 0;
 }