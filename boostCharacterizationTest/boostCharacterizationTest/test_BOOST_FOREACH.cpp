#include <iostream>
#include <gmock\gmock.h>
#include <boost\foreach.hpp>

using ::testing::StrEq;

TEST(boostTest, test_BOOST_FOREACH){
	const int ar[] = { 3, 1, 4 };
	std::stringstream sut;

	BOOST_FOREACH(int x, ar){
		sut << x << ",";
	}
	ASSERT_THAT(sut.str(), StrEq("3,1,4,"));
}