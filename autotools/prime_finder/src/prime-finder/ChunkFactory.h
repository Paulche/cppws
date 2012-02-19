/* 
 * File:   ChunkFactory.h
 * Author: paul
 *
 * Created on February 11, 2012, 6:43 PM
 */

#ifndef CHUNKFACTORY_H
#define	CHUNKFACTORY_H

#include "limits.h"
#include "Chunk.h"
#include <list>

namespace PrimeFinder
{

    class ChunkFactory {
    public:
        ChunkFactory();
        ChunkFactory(const ChunkFactory& orig);
        virtual ~ChunkFactory();
        
        long getMaxPrimeNum();
        
        long reset();
        
        long next();
        
        long allocatedMax();
        
        bool check(long i);
        
        void setUnprime(long i);
        
        void allocate();
        
        void setMaxPrimeNum();
        
        long find_cached(unsigned int num);

    private:
        
        std::list<Chunk *> chunks;
        
        long nextOffset;
        
        unsigned int maxPrimeNum;
        
        std::list<Chunk *>::iterator currentChunk;
        std::list<Chunk *>::iterator currentCheckChunk;
        
        long currentOffsetChunk;

        

    };

}

#endif	/* CHUNKFACTORY_H */

