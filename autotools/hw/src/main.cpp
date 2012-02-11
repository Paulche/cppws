/* 
 * File:   main.cpp
 * Author: Paul Chechetin
 *
 * Created on February 10, 2012, 11:53 PM
 */

#include <cstdlib>
#include <iostream>


#include "Finder.h"


extern void test();

int main(int argc, char** argv) 
{
    
    PrimeFinder::Finder finder = PrimeFinder::Finder();
    
    unsigned int num = atoi(argv[1]);
    
    long prime = finder.find(num);
    
    std::cout << prime << std::endl;
        
    /*
    test();
    */
    
    return 0;
}

