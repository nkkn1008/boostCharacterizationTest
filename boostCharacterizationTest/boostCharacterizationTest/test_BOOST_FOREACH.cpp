#include <iostream>
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
}