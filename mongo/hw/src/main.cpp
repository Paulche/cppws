//main.cpp

#include <iostream>

#include <client/dbclient.h>

int main ( int argc, char ** argv )
{
	mongo::DBClientConnection conn;

	std::string errmsg;

	if ( ! conn.connect( string( "127.0.0.1:27017" ), errmsg ) ) 
	{
        std::cerr << "couldn't connect : " << errmsg << std::endl;
        return -1;
    }

    mongo::BSONObjBuilder obj;
    
    obj.append( "hello" , "world" );

    conn.insert( "test.hw" , obj.obj() );

    std::cout << "Insert finished successfully" << std::endl;

    return 0;

}