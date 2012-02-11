/* 
 * File:   Finder.h
 * Author: paul
 *
 * Created on February 11, 2012, 12:02 AM
 */

#ifndef FINDER_H
#define	FINDER_H

#include "limits.h"
#include "Chunk.h"


#include <list>


namespace PrimeFinder
{

    class Finder {
    public:
        Finder();
        Finder(const Finder& orig);
        virtual ~Finder();
        
        
        long find ( unsigned int num );
        
    private:
        
        //Find prime number in cache
        long find_cached(long num);
        
        //Maximum for known prime numbers
        long prime_max_num;
        
        
        //Offset for next chunk
        long next_chunk_offset;
        
        std::list<Chunk> chunks;
        
        
        
        

    };

}

#endif	/* FINDER_H */

