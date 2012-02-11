/* 
 * File:   Finder.cpp
 * Author: paul
 * 
 * Created on February 11, 2012, 12:02 AM
 */

#include "Finder.h"
#include "Chunk.h"
#include "ChunkFactory.h"

namespace PrimeFinder
{

    Finder::Finder()
    {
        
    }

    Finder::Finder(const Finder& orig) {
    }

    Finder::~Finder() {
    }
    
    long Finder::find(unsigned int num)
    {
        ChunkFactory factory = ChunkFactory();
        
        while ( factory.getMaxPrimeNum() < num )
        {
            factory.allocate();
            
            for ( unsigned int i = factory.reset(); i*i < factory.allocatedMax(); i = factory.next() )
            {
                for ( unsigned int j = i*i; j < factory.allocatedMax(); j += i )
                {
                    if ( factory.check(j) )
                    {
                        factory.setUnprime(j);
                    }
                }
            }
            
            factory.setMaxPrimeNum();
        }
        
        return factory.find_cached(num);
        
    }
}
