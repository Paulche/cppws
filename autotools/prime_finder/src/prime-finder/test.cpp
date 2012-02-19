/* 
 * File:   test.cpp
 * Author: paul
 *
 * Created on February 11, 2012, 10:20 AM
 */

#include <cstdlib>
#include <iostream>
#include <list>

#define CHUNK_SIZE 1024

void init_chunk ( bool * chunk, size_t size );

size_t finalize_chunk ( bool * chunk, size_t size, unsigned int ** result);

void test() 
{
    /*
        Вход: натуральное число n

        Пусть A — булевый массив, индексируемый числами от 2 до n, 
        изначально заполненный значениями true.
    */
    
    bool chunk[CHUNK_SIZE] = {NULL}; 

    init_chunk(chunk, CHUNK_SIZE);
    
    unsigned int i = 2;
    
    for ( unsigned int i = 2; i*i < CHUNK_SIZE; ++i )
    {
        if ( chunk[i] == true )
        {
            for ( unsigned int j = i*i; j <= CHUNK_SIZE; j += i )
            {
                if ( chunk[j] == true )
                {
                    chunk[j] = false;
                }
            }
        }
    }
    
    unsigned int * result;
    
    size_t count = finalize_chunk(chunk, CHUNK_SIZE, &result );
    
    for ( size_t i = 0; i < count; ++i )
    {
        std::cout << *(result + i) << std::endl; 
    }
    
    delete [] result;
    
    /*
    
        для i := 2, 3, 4, ..., пока i^2 ≤ n:
        если A[i] == true:
            для j := i^2, i^2 + i, i^2 + 2i, ..., пока j ≤ n:
            если A[j] == true:
                A[j] := false
                count := count - 1

        Теперь все числа i, такие что A[i] == true, являются простыми, 
        а переменная count содержит в себе их общее количество в массиве.
    
     */
}

void init_chunk ( bool * chunk, size_t size )
{
    for ( bool * iter = chunk + 2 ; iter < chunk + size; ++iter )
    {
        *iter = true;
    }
}

/**
 * The caller of this function must release memory.
 * 
 * @param chunk pointer to chunk array
 * @param size size of array
 * @param result pointer to pointer for result
 * @return size of node in result
 */
size_t finalize_chunk ( bool * chunk, size_t size, unsigned int ** result )
{
    std::list<unsigned int> list = std::list<unsigned int>();
    
    for (  bool * iter = chunk; iter < chunk + size; ++iter )
    {
        if ( *iter == true )
        {                    
            list.push_back(iter - chunk);
        }
    }
    
    *result = new unsigned int[list.size()];
    
    size_t offset = 0;
      
    for ( std::list<unsigned int>::iterator iter = list.begin(); iter != list.end(); ++iter )
    {
        
        *(*result + offset) = *iter;
        
        ++offset;
    }
    
    
    
    return offset;
}