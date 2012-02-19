//server.hpp

#ifndef SERVER_H
#define SERVER_H

#include "session.hpp"

#include <boost/config.hpp>
#include <boost/system/system_error.hpp>
#include <boost/system/error_code.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using namespace boost::system;


class Server
{
	public:
  		Server(boost::asio::io_service& io_service, short port);
	
	private:
 	 	void start_accept();

  		void handle_accept(Session* new_session, const boost::system::error_code& error);

  		boost::asio::io_service& io_service_;
  		tcp::acceptor acceptor_;
};

#endif