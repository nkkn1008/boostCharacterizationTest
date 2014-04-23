#include <iostream>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <boost/function.hpp>

using ::testing::Eq;
using ::testing::StrEq;

namespace{
	int add(int a, int b){
		return  a + b;
	}

	TEST(test_function_pointer, store_function_pointer){
		boost::function<int(int, int)> f = add;		
		const int actual = f(2, 3);
		ASSERT_THAT(actual, Eq(5));
	}
}