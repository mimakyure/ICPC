#define BOOST_TEST_MODULE Tests
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "solution.h"


BOOST_AUTO_TEST_CASE(Case1)
{
  // Run solution using prepared input data
  std::ifstream if_input("input.txt");
  BOOST_REQUIRE(if_input.good());
  std::streambuf* old_cin = std::cin.rdbuf(if_input.rdbuf());

  // Collect output from solution
  std::stringstream ss_output;
  std::streambuf* old_cout = std::cout.rdbuf(ss_output.rdbuf());


  solution();


  // Prepare output for tests
  std::vector<std::string> output;
  for (std::string line; std::getline(ss_output, line); ) {
    output.push_back(line);
  }

  // Test solution output against verified output
  std::ifstream if_verified("output.txt");
  BOOST_REQUIRE(if_verified.good());
  int count = 0;

  for (std::string verified; std::getline(if_verified, verified); ) {
   
    BOOST_TEST(verified == output.at(count));

    ++count;
  }

  // Check solution didn't output additional lines
  BOOST_TEST(count == output.size());


  // Restore original std::cout and std::cin
  std::cout.rdbuf(old_cout);
  std::cin.rdbuf(old_cin);
}
