#define BOOST_TEST_MODULE Tests
#include <boost/test/included/unit_test.hpp>
#include <fstream>
#include <iterator>
#include "solution.h"


BOOST_AUTO_TEST_CASE(Case1)
{
  // Test solution output against verified file data
  boost::test_tools::output_test_stream output("output.txt", true, true);
  std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());


  // Run solution using prepared input data
  std::ifstream ifin("input.txt");
  BOOST_REQUIRE(ifin.good());
  std::streambuf* old_cin = std::cin.rdbuf(ifin.rdbuf());
  


  solution();



  BOOST_TEST(output.match_pattern());


  // Restore original std::cout and std::cin
  std::cout.rdbuf(old_cout);
  std::cin.rdbuf(old_cin);
}


