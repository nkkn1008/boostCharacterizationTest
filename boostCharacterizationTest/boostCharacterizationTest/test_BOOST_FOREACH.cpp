#include <iostream>
#include <map>
#include <string>

#include <gmock/gmock.h>
#include <boost/foreach.hpp>

using ::testing::StrEq;

namespace{
	TEST(test_BOOST_FOREACH, simple_iterate){
		const int ar[] = { 3, 1, 4 };
		std::stringstream actual;

		BOOST_FOREACH(int x, ar){
			actual << x << ",";
		}
		ASSERT_THAT(actual.str(), StrEq("3,1,4,"));
	}

	TEST(test_BOOST_FOREACH, rewrite_each_element){
		int ar[] = { 3, 1, 4 };
		std::stringstream actual;

		BOOST_FOREACH(int& x, ar){
			++x;
		}

		BOOST_FOREACH(int x, ar){
			actual << x << ",";
		}
		ASSERT_THAT(actual.str(), StrEq("4,2,5,"));
	}

	TEST(test_BOOST_FOREACH, map_iterate){
		std::stringstream actual;
		std::map<int, std::string> m;
		m[3] = "a";
		m[1] = "b";
		m[4] = "c";

		typedef std::map<int, std::string>::const_reference type;
		BOOST_FOREACH(type x, m){
			actual << x.first << "," << x.second << ",";
		}
		ASSERT_THAT(actual.str(), StrEq("1,b,3,a,4,c,"));
	}
}