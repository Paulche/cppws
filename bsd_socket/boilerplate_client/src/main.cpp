//main.cpp

#include <iostream>
#include <cstring>


#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <boost/scoped_array.hpp>

#define BUFFER_SIZE 256

void error ( const char * );

int main ( int argc, char ** argv )
{
	std::cout << "Begin" << std::endl;
	{
		int sock;
		struct sockaddr_in addr;
		const char * start_message = "GET / HTTP/1.0\n\n";
		boost::scoped_array<char> buff(new char[BUFFER_SIZE]);

		sock = socket ( AF_INET, SOCK_STREAM, 0 );

		if ( sock < 0 )
			error ( "Invalid socket initialization" );

		addr.sin_family = AF_INET;
		addr.sin_port = htons(80);						//TODO:
		addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);	//TODO:

		std::cout << "Try to connect" << std::endl;

		bool errno = connect(sock, (const sockaddr *) &addr, sizeof(addr));

		if ( errno < 0)
			error ( "Invalid socket connection");

		std::cout << "Connection ready" << std::endl << "Try to send data" << std::endl;

		send (sock, start_message, std::strlen(start_message), 0);

		std::cout << "Data sended" << std::endl << "Try to receive data" << std::endl;

		std::cout << std::endl << "*** Start data ***" << std::endl;

		while ( recv (sock, buff.get(), BUFFER_SIZE, 0) != 0 )
		{
			std::cout << buff.get();
		}

		std::cout << std::endl << "*** End data ***" << std::endl;

		std::cout << "Data received" << std::endl;

		close (sock);	

	}

	std::cout << "End" << std::endl;
	
	return 0;
}


void error ( const char * message )
{
	std::cerr << message << std::endl;
	exit ( -1 );
}
