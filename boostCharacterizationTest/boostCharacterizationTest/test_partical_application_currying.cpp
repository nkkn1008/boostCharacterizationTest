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
		// ‘æ‚Pˆø”‚Ì‚İ‚ğæ‚É“n‚·
		boost::function<int(int, int)> f = boost::bind(add, 2, _1, _2);

		// c‚è‚Ìˆø”‚ğ“n‚µ‚ÄŠÖ”‚ğŒÄ‚Ño‚·
		const int actual = f(3, 4);
		
		ASSERT_THAT(actual, Eq(9));
	}
}

