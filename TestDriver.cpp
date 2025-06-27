#define BOOST_TEST_MODULE SkeletalTestDriver
#define BOOST_TEST_NO_MAIN 

#include <boost/test/unit_test.hpp>

int main(int argumentCount, char *argumentVector[])
{

  return boost::unit_test::unit_test_main(&init_unit_test, argumentCount, argumentVector);

}
