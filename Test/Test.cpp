#define BOOST_TEST_MODULE Tests
#include <boost/test/included/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>
#include <chrono>
#include "solution.h"


BOOST_AUTO_TEST_CASE(Correctness1)
{
  // Test output against file data
  boost::test_tools::output_test_stream output("output.txt", true);
  std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());

  // Run function against prepared input file data
  std::ifstream ifin("input.txt");
  std::streambuf* old_cin = std::cin.rdbuf(ifin.rdbuf());

    
  solution();


  BOOST_TEST(output.match_pattern());

  // Restore original std::cout and std::cin
  std::cout.rdbuf(old_cout);
  std::cin.rdbuf(old_cin);


}
