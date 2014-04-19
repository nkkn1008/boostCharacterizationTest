#include <iostream>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <boost/format.hpp>

using ::testing::Eq;
using ::testing::StrEq;

namespace{
	TEST(test_string_format, format_like_printf){
		std::stringstream actual;
		actual << boost::format("%d %s") % 3 % std::string("Hello");
		ASSERT_THAT(actual.str(), StrEq("3 Hello"));
	}

	TEST(test_string_format, format_str_method){
		std::string actual = (boost::format("%2% %1%") % 3 % std::string("Hello")).str();
		ASSERT_THAT(actual, StrEq("Hello 3"));
	}
}