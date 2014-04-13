#include <iostream>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <boost/algorithm/string/trim.hpp>

using ::testing::StrEq;

namespace{
	TEST(test_string_handling, trim_copy){
		const std::string s = "   abc   ";
		std::string actual = boost::trim_copy(s);

		ASSERT_THAT(actual, StrEq("abc"));
	}

}