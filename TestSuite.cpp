#include "Logger.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(LoggerTest)

BOOST_AUTO_TEST_CASE(LogWrite)
{

  try {

  
    GLOBAL_LOG("A String A Sentence A Phrase")


  } catch(std::exception &anException) {

    BOOST_FAIL(anException.what());

  }


}

BOOST_AUTO_TEST_CASE(LogWriteString)
{

  try {

  
    GLOBAL_LOG_DECLARATION(std::string aString("Something"));
    GLOBAL_LOG(aString);

  } catch(std::exception &anException) {

    BOOST_FAIL(anException.what());

  }


}

BOOST_AUTO_TEST_SUITE_END()
