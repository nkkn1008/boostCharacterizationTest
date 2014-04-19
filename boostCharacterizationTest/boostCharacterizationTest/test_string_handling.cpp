#include <iostream>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string/join.hpp>

using ::testing::Eq;
using ::testing::StrEq;

namespace{
	TEST(test_string_handling, trim_copy){
		const std::string s = "   abc   ";
		std::string actual = boost::trim_copy(s);

		ASSERT_THAT(actual, StrEq("abc"));
	}

	TEST(test_string_handling, split_using_comma){
		const std::string s = "abc,123,xyz";
		std::vector<std::string> expected = boost::assign::list_of("abc")("123")("xyz");

		std::vector<std::string> actual;
		boost::algorithm::split(actual, s, boost::is_any_of(","));	
		
		ASSERT_THAT(actual, Eq(expected));		
	}

	TEST(test_string_handling, split_using_slash_or_space){
		const std::string s = "a/b/c d";
		std::vector<std::string> expected = boost::assign::list_of("a")("b")("c")("d");

		std::vector<std::string> actual;
		boost::algorithm::split(actual, s, boost::is_any_of("/ "));

		ASSERT_THAT(actual, Eq(expected));
	}

	TEST(test_string_handling, join){
		const std::vector<std::string> v = {"a", "b", "c"};

		const std::string actual = boost::algorithm::join(v, ",");
		ASSERT_THAT(actual, StrEq("a,b,c"));
	}

}