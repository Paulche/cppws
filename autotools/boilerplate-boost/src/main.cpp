#include <iostream>
#include <cstdlib>

#include <boost/asio.hpp>


/*
unsigned int fact(unsigned int n);
unsigned int fact_imp(unsigned int n, unsigned int acc);

int main ( int argc, char ** argv )
{
    std::cout << fact(10) << std::endl;
}

unsigned int fact(unsigned int n)
{
	return fact_imp(n, 1);
}

unsigned int fact_imp(unsigned int n, unsigned int acc)
{
	if ( n <= 1)
	{
		return acc;
	}
	else
	{
		return fact_imp(n-1, acc*n);
	}

}
*/

#include "server.hpp"

int main ( int argc, char** argv )
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: async_tcp_echo_server <port>" << std::endl;
      return 1;
    }

    boost::asio::io_service io_service;

    Server s(io_service, std::atoi(argv[1]));

    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}