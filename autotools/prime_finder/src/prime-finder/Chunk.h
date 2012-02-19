/* 
 * File:   Chunk.h
 * Author: paul
 *
 * Created on February 11, 2012, 12:01 AM
 */

#ifndef CHUNK_H
#define	CHUNK_H

#include "limits.h" 

#include <map>

namespace PrimeFinder
{

    class Chunk {
    
    public:
        Chunk( long offset, unsigned int startNum );
        Chunk(const Chunk & orig);
        virtual ~Chunk();
        
        
        //Just return chunk to first state
        long reset();
       
        //Release memory for chunk 'cause all work is done
        void close();
        
        bool hasNext();
        
        long next();
        
        void setUnprime( long i );
        
        bool check( long i );
        
        bool checkBound(long i);

        long getMaxPrimeNum();

    private:
        const unsigned int floor;
        const unsigned int ceil;
        const unsigned int startNum;

        //Offset from NULL for this chunk
        const long offset;

        unsigned int num;

        long current;
        
        //Global num of prime => prime value
        std::map<long,long> primes;
        
        //Chunk array pointer
        bool * chunk;

    };

}

#endif	/* CHUNK_H */

