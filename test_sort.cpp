#include "gtest/gtest.h"

#include "msort.h"
#include <vector>
#include <iostream>

class MergeSortTest : public testing::Test
{

public:
	MergeSortTest() {};
	~MergeSortTest() {};

	void SetUp() {
		vi.push_back(7);
		vi.push_back(-5);
		vi.push_back(8);
		vi.push_back(-2);
		vi.push_back(1);

		vs.push_back("juice");
		vs.push_back("apple");
		vs.push_back("pear");
	}

	void TearDown() {
		vi.clear();
		vs.clear(); 
	}

	std::vector<int> vi;
	std::vector<std::string> vs;

	AscComp compAsc;
	// AbsAscComp compAbsAsc;
	DscComp compDesc;
	AlphaStrComp compAlpha;
	LengthStrComp compLen;
};

TEST_F(MergeSortTest, IntAscendTest) {
	mergeSort (vi, compAsc);
	EXPECT_EQ(vi[0], -5);
	EXPECT_EQ(vi[2], 1);
	EXPECT_EQ(vi[4], 8);
}

// TEST_F(MergeSortTest, IntAbsAscendTest) {
// 	mergeSort (vi, compAbsAsc);
// 	EXPECT_EQ(vi[0], 1);
// 	EXPECT_EQ(vi[2], -5);
// 	EXPECT_EQ(vi[4], 8);
// }

TEST_F(MergeSortTest, IntDescendTest) {
	mergeSort (vi, compDesc);
	EXPECT_EQ(vi[0], 8);
	EXPECT_EQ(vi[2], 1);
	EXPECT_EQ(vi[4], -5);
}

TEST_F(MergeSortTest, StringAlpha) {
	mergeSort (vs, compAlpha);
	EXPECT_EQ(vs[0], "apple"); // works?
	EXPECT_EQ(vs[1], "juice");
	EXPECT_EQ(vs[2], "pear");
}

TEST_F(MergeSortTest, StringLength) {
	mergeSort (vs, compLen);
	EXPECT_EQ(vs[0], "pear");
	EXPECT_EQ(vs[1], "apple");
	EXPECT_EQ(vs[2], "juice");
}
