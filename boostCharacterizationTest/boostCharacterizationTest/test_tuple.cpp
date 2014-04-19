#include <iostream>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/at_c.hpp>

using ::testing::Eq;
using ::testing::StrEq;

namespace{
	TEST(test_tuple, at_c_n){
		namespace fusion = boost::fusion;
		const fusion::vector<int, char, std::string> v(1, 'a', "Hello");
		
		ASSERT_THAT(fusion::at_c<0>(v), Eq(1));
		ASSERT_THAT(fusion::at_c<1>(v), Eq('a'));
		ASSERT_THAT(fusion::at_c<2>(v), StrEq("Hello"));
	}

}