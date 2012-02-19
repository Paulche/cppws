/* 
 * File:   main.cpp
 * Author: Paul Chechetin
 *
 * Created on February 10, 2012, 11:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#include <yaml-cpp/yaml.h>

#include "Finder.h"

#define NUM_OF_TEST 5


extern void test();

int main(int argc, char** argv) 
{
 	
    /*
    unsigned int num[NUM_OF_TEST] = {10,100,1000,10000,20000}; 

 	long result[NUM_OF_TEST] = {}; 

    PrimeFinder::Finder finder = PrimeFinder::Finder();

    std::cout << "Start computing" << std::endl;

    for ( size_t i = 0; i < NUM_OF_TEST; ++i)
    {
    	result[i] = finder.find(num[i]);
    }

    std::cout << "Computing is done" << std::endl;
        
    for ( size_t i = 0; i < NUM_OF_TEST; ++i )
    {
    	std::cout << "Prime[" << num[i] << "] = " << result[i] << std::endl;
    }

    std::cout << "Exit" << std::endl;
    */

    std::ofstream ofile;

    YAML::Emitter out;

    ofile.open("./fixture.yaml");

    out << YAML::BeginSeq;
    out << "One";
    out << "Two";
    out << "Three";
    out << YAML::EndSeq;


    ofile << out.c_str();

    ofile.close();

    return 0;
}
