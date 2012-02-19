//main_test.cpp

#include <gtest/gtest.h>

extern int foo();

class MainTest : public testing::Test
{

};

TEST_F(MainTest, test1)

{

  	ASSERT_EQ(foo(), 1);

}


int main ( int argc, char ** argv )

{

 	testing::InitGoogleTest(&argc, argv);

 	return RUN_ALL_TESTS();

} 