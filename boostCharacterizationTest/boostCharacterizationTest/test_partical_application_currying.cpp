#include <iostream>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <boost/function.hpp>
#include <boost/bind.hpp>

using ::testing::Eq;
using ::testing::StrEq;

namespace{
	int add(int a, int b, int c){
		return a + b + c;
	}
	TEST(test_partical_application, binding){
		// 第１引数のみを先に渡す
		boost::function<int(int, int)> f = boost::bind(add, 2, _1, _2);

		// 残りの引数を渡して関数を呼び出す
		const int actual = f(3, 4);
		
		ASSERT_THAT(actual, Eq(9));
	}
}

