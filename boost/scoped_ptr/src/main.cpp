//main.cpp

#include <iostream>
#include <stdexcept>

#include <boost/scoped_ptr.hpp>

class Foo
{
public:

	Foo( const char * name):
		name(name)
	{
		std::cout << "Foo:constuct:" << name << std::endl;
	}

	void throw_error() throw(std::logic_error)
	{
		throw std::logic_error ( name );
	}

	std::string toString()
	{
		return name;
	}

	virtual ~Foo()
	{
		std::cout << "Foo:destruct:" << name << std::endl;
	}
private:
	std::string name;
};

std::ostream & operator<< ( std::ostream & stream, Foo & foo );


int main ( int argc, char ** argv )
{
	boost::scoped_ptr<Foo> sc_ptr( new Foo("Smart") );
	Foo * foo_norm = new Foo("Non-Smart");
	Foo * foo_ptr = sc_ptr.get();
	Foo & foo_ref = *sc_ptr;

	std::cout << "Start program" << std::endl;

	try
	{
		std::cout << foo_ptr << std::endl;

		std::cout << foo_ref << std::endl;

		std::cout << *sc_ptr << std::endl;

		sc_ptr->throw_error();

		delete foo_norm;
	}
	catch(std::logic_error & e)
	{
		std::cout << "Logic error:" << e.what() << std::endl;
	}

	std::cout << "End program" << std::endl;

};


std::ostream & operator<< ( std::ostream & stream, Foo & foo )
{
	return stream << foo.toString();
}

