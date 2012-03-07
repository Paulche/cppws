//main.cpp

#include <iostream>
#include <string>

#include <cstring>
#include <cstdlib>

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <boost/scoped_array.hpp>

#define BUFFER_SIZE 256

void reverse ( char * buff, unsigned int size );

int main ( int argc, char ** argv )
{
	if ( argc < 3 )
	{
		std::cout << "Too few arguments" << std::endl;
		return EXIT_FAILURE;
	}


	for (;;)
	{
		boost::scoped_array<char> buffer(new char[BUFFER_SIZE]);
		
		std::cin.getline(buffer.get(), BUFFER_SIZE);

		reverse(buffer.get(), BUFFER_SIZE);

		std::cout << buffer.get() << std::endl; 
	}

	return EXIT_SUCCESS;
}

void reverse( char * buff, unsigned int size )
{
	unsigned int length = std::strlen(buff);

	boost::scoped_array<char> rev_buff(new char[size]);
	
	std::strcpy(rev_buff.get(), buff);

	for ( char * s = rev_buff.get() + length - 1, * d = buff; s >= rev_buff.get(); --s, ++d )
	{
		*d = *s; 
	}	
}

