/* 
 * File:   main.cpp
 * Author: paul
 * Purpose: Testing of prime-finder library by Google Test Framework
 * Created on February 18, 2012, 12:01 AM
 */

#include <utility>
#include <list>
#include <fstream>

#include <yaml-cpp/yaml.h>
#include <gtest/gtest.h>

#include "../prime-finder/Finder.h" 

#define FIXTURE_FILE_PATH "./fixture.yaml"


class PrimeFinderTest : public testing::Test
{
public:
	PrimeFinderTest();

	std::list<std::pair<unsigned int,long> > fixture;
	PrimeFinder::Finder finder;
};

PrimeFinderTest::PrimeFinderTest()
{
	std::ifstream file;

	file.open(FIXTURE_FILE_PATH);

	try
	{
		YAML::Parser parser(file);

		YAML::Node doc;

		parser.GetNextDocument(doc);

		for ( YAML::Iterator it = doc.begin(); it != doc.end(); ++it )
		{
			const YAML::Node & node = *it;
			
			unsigned int input;
			long output;

			node["input"] >> input;
			node["output"] >> output;

			fixture.push_back
			(
				std::pair<unsigned int, long>(input,output)
			);
		}
	}
	catch ( YAML::ParserException& e )
	{
		std::cerr << "Something was wrong: " << e.what() << std::endl;
	}
}

TEST_F(PrimeFinderTest, isFindReturnRigthResult)
{ 
	for ( std::list<std::pair<unsigned int, long> >::iterator it = this->fixture.begin(); it != this->fixture.end(); ++it )
	{
  		ASSERT_EQ
  		(
  			this->finder.find((*it).first),
  			(*it).second
  		);
  	}
}


int main ( int argc, char ** argv )
{

 	testing::InitGoogleTest(&argc, argv);

 	return RUN_ALL_TESTS();

} 