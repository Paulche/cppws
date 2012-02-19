#define BOOST_TEST_MODULE MainTest

#include <boost/test/unit_test.hpp>

extern unsigned int fac ( unsigned int );

BOOST_AUTO_TEST_CASE( main_test )
{
	BOOST_CHECK( fac ( 10 ) == 3628800 ); 
}