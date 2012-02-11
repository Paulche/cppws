/* 
 * File:   Chunk.cpp
 * Author: paul
 * 
 * Created on February 11, 2012, 12:01 AM
 */

#include "Chunk.h"

namespace PrimeFinder
{

	Chunk::Chunk(long offset, unsigned int startNum):
        offset(offset),
        floor(offset),
        ceil(offset + CHUNK_SIZE - 1),
        current(0),
        startNum(startNum)
    {

    	this->chunk = new bool[CHUNK_SIZE];
        
        for ( bool * p = this->chunk; p < this->chunk + CHUNK_SIZE; ++p )
        {
            *p = true;
        }
        
    }

	/*
	Chunk::Chunk(const Chunk & orig ):
			offset(0)
	{
		int i = 9;

		++i;
	}
	*/
    
    //Just return chunk to first state
    long Chunk::reset()
    {
        this->current = 0;
        
        while ( *(this->chunk + this->current) != true )
        {
            ++this->current;
        }
        
        return this->offset + this->current;
    }

    //Release memory for chunk 'cause all work is done
    void Chunk::close()
    {
        
    }

    bool Chunk::hasNext()
    {
        bool * base = this->chunk + this->current + 1;
        
        while ( (base - this->chunk) < CHUNK_SIZE )
        {
            if ( *base == true )
            {
                return true;
            }
            else
            {
            	++base;
            }
        }
        
        return false;

    }

    long Chunk::next()
    {
       ++this->current;

       bool * p = this->chunk + this->current;
        
       while ( *p != true  )
       {
          ++p; 
       }

       this->current  =  p - this->chunk;
        
       return this->offset + this->current;
    }
    
    void Chunk::setUnprime( long i )
    {
        long local = i - offset;
        
        *(chunk + local) = false;
    }

    bool Chunk::check( long i )
    {
        long local = i - offset;
        
        return *(chunk + local);
    }
    
    bool Chunk::checkBound( long i )
    {
    	if ( ( i >= this->floor ) && ( i <= this->ceil ) )
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }

    long Chunk::getMaxPrimeNum()
    {
    	unsigned int pos = this->startNum;

        bool * p = chunk;
        
        while ( p < chunk + CHUNK_SIZE  )
        {
            if ( *p == true )
            {
            	++pos;
            }

            ++p;
        }    
        
        return pos;
    }

    Chunk::~Chunk()
    {
    	delete [] this->chunk;
    }

}
