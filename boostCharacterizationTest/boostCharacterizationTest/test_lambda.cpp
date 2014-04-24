#include <iostream>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <boost/lambda/lambda.hpp>
#include <boost/range/algorithm/find_if.hpp>
#include <boost/assign/list_of.hpp>

using ::testing::Eq;
using ::testing::StrEq;

namespace{
	TEST(test_lambda, basic_usage){
		std::vector<int> v = boost::assign::list_of(1)(2)(3);
		using boost::lambda::_1;
		std::vector<int>::iterator it = boost::find_if(v, _1 == 3);
		ASSERT_THAT(*it, Eq(2));
	}
}