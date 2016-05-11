#include "gtest/gtest.h"
#include <functional> 
#include <string>

// #ifndef _CONTAINER_DEFINITIONS_H
// #define _CONTAINER_DEFINITIONS_H

// #define VECTOR 1
// #define LIST 0
// #define DEQUE 0

// #if VECTOR
// 	#include <vector>
// 	template <class T>
// 	using CONTAINER = std::vector<T>;
// #elif LIST
// 	#include <list>
// 	template <typename T>
// 	using CONTAINER = std::list<T>;
// #elif DEQUE
// 	#include <deque>
// 	template <typename T>
// 	using CONTAINER = std::deque<T>;
// #endif

// #endif


// Intentionally left blank -- Include the student's msort.h file here.
#include "msort.h"

// Change the function call to match the name of the merge sort function provided
// by the student.
#define MERGE_SORT(container, comparator) mergeSort(container, comparator);

#define RUN_TIME_TESTS 1

#include <vector>
// template <class T>
// using CONTAINER = std::vector;

#define CONTAINER std::vector

// Constructs a list by adding the items in the int array. 
template<typename T>
void ConstructList(CONTAINER<T>& container, int numberOfItems, T items[])
{
	int numberOfInsertedItems(0);
	while(numberOfInsertedItems < numberOfItems)
	{
		container.push_back(items[numberOfInsertedItems]);
		++numberOfInsertedItems;
	}
}

// Constructs a list by adding a random number of items to the container. 
void ConstructList(CONTAINER<int>& container, int numberOfItems)
{
	int numberOfInsertedItems(0);
	while(numberOfInsertedItems < numberOfItems)
	{
		container.push_back(rand());
		++numberOfInsertedItems;
	}
}

// Constructs a list by adding items. 
template<typename T1, typename T2>
void ConstructList(CONTAINER<std::pair<T1, T2> >& container, int numberOfItems, std::pair<T1, T2> items[])
{
	int numberOfInsertedItems(0);
	while(numberOfInsertedItems < numberOfItems)
	{
		container.push_back(items[numberOfInsertedItems]);
		++numberOfInsertedItems;
	}
}

// A macro to check the order of the contents of a given container. The container,
// expected number of items, and a comparator object are passed here. Then the
// container is traversed using iterators and comparing values during the traversal. 
#define CHECK_ORDER(CONTAINER, NUMBER_OF_ITEMS, COMPARATOR) { \
	auto iter = CONTAINER.begin(); \
	int numberOfItems = 0; \
	for(int i = NUMBER_OF_ITEMS; i >= 0; --i) { \
		if(i == 0) { \
			EXPECT_EQ(numberOfItems, CONTAINER.size()); \
		} \
		else { \
			if(iter == CONTAINER.end()) { \
				ASSERT_FALSE(true); \
			} \
			auto nextIter = iter; \
			std::advance(nextIter, 1); \
			++numberOfItems; \
			if(nextIter != CONTAINER.end()) { \
				auto previous = *iter; \
				auto next = *nextIter; \
				EXPECT_TRUE(COMPARATOR(previous, next)); \
			} \
			std::advance(iter, 1); \
		} \
	} \
	EXPECT_EQ(NUMBER_OF_ITEMS, numberOfItems); \
}

// Generic <= comparator. 
template<typename T>
struct CompLessEq
{
	bool operator()(const T& lhs, const T& rhs)
	{
		return lhs <= rhs;
	}
};

// Generic >= comparator. 
template<typename T>
struct CompGreaterEq
{
	bool operator()(const T& lhs, const T& rhs)
	{
		return lhs >= rhs;
	}
};

template<typename T1, typename T2>
struct PairFirstLess
{
	bool operator()(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
	{
		return lhs.first < rhs.first;
	}
};

template<typename T1, typename T2>
struct PairsecondLess
{
	bool operator()(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
	{
		return lhs.second < rhs.second;
	}
};

template<typename T1, typename T2>
struct PairFirstGreater
{
	bool operator()(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
	{
		return lhs.first > rhs.first;
	}
};

template<typename T1, typename T2>
struct PairSecondGreater
{
	bool operator()(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
	{
		return lhs.second > rhs.second;
	}
};

template <typename T1, typename T2>
struct PairFirstLessEq
{
	bool operator()(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
	{
		return lhs.first <= rhs.first;
	}
};

template <typename T1, typename T2>
struct PairFirstGreaterEq
{
	bool operator()(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
	{
		return lhs.first >= rhs.first;
	}
};

class MSortTest : public testing::Test
{
	protected:
		MSortTest()
		{ 

		}
		~MSortTest()
		{ 

		}

		virtual void SetUp() 
		{

		}

		virtual void TearDown() 
		{

		}

		// The two kinds of containers. 
		CONTAINER<int> mIntContainer;
		CONTAINER<std::string> mStringContainer;
		CONTAINER<std::pair<std::string, int> > mStringIntPairContainer;

		// Different comparators. 
		std::less<int> mIntLessComp;
		CompLessEq<int> mIntLessEqComp;
		std::greater<int> mIntGreaterComp;
		CompGreaterEq<int> mIntGreaterEqComp;
		std::less<std::string> mStringLessComp;
		CompLessEq<std::string> mStringLessEqComp;
		std::greater<std::string> mStringGreaterComp;
		CompGreaterEq<std::string> mStringGreaterEqComp;
		PairFirstLess<std::string, int> mStringIntPairLessComp;
		PairFirstGreater<std::string, int> mStringIntPairGreaterComp;
		PairFirstLessEq<std::string, int> mStringIntPairLessEqComp;
		PairFirstGreaterEq<std::string, int> mStringIntPairGreaterEqComp;
};

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

/*
	These are tests for integers. In total, there are 12 tests for the integers. They are:
	1. IntInOrderLess -- Checks on list that is already sorted in increasing order.
	2. IntInOrderGreater -- Checks on list that is already sorted in decreasing order. 
	3. IntScrambledLess -- Checks on list with scrambled integers, and looks for increasing order. 
	4. IntScrambledGreater -- Checks on list with scrambled integers, and looks for decreasing order.
	5. IntDuplicateLess -- Checks on list with scrambled integers containing duplicates, looking for increasing.
	6. IntDuplicateGreater -- Checks on list with scrambled integers containing duplicates, looks for decreasing.
	7 - 9. IntLarge*Less -- Inserts 10,000/100,000/1,000,000 random integers and looks for increasing order.
	10 - 12. IntLarge*Greater -- Inserts 10,000/100,000/1,000,000 random integers and looks for decreasing order. 
*/

TEST_F(MSortTest, IntInOrderLess_01)
{
	int elements[] = { 0, 1, 2, 3, 4, 5 };
	ConstructList(mIntContainer, sizeof(elements) / sizeof(int), elements);
	MERGE_SORT(mIntContainer, mIntLessComp);
	CHECK_ORDER(mIntContainer, sizeof(elements) / sizeof(int), mIntLessComp);
}


TEST_F(MSortTest, IntInOrderGreater_02)
{
	int elements[] = { 5, 4, 3, 2, 1, 0 };
	ConstructList(mIntContainer, sizeof(elements) / sizeof(int), elements);
	MERGE_SORT(mIntContainer, mIntGreaterComp);
	CHECK_ORDER(mIntContainer, sizeof(elements) / sizeof(int), mIntGreaterComp);
}

TEST_F(MSortTest, IntScrambledLess_03)
{
	int elements[] = { 0, 5, 3, 2, 4, 1 };
	ConstructList(mIntContainer, sizeof(elements) / sizeof(int), elements);
	MERGE_SORT(mIntContainer, mIntLessComp);
	CHECK_ORDER(mIntContainer, sizeof(elements) / sizeof(int), mIntLessComp);
}

TEST_F(MSortTest, IntScrambledGreater_04)
{
	int elements[] = { 0, 5, 3, 2, 4, 1 };
	ConstructList(mIntContainer, sizeof(elements) / sizeof(int), elements);
	MERGE_SORT(mIntContainer, mIntGreaterComp);
	CHECK_ORDER(mIntContainer, sizeof(elements) / sizeof(int), mIntGreaterComp);
}

TEST_F(MSortTest, IntDuplicateLess_05)
{
	int elements[] = { 0, 1, 3, 3, 1, 5 };
	ConstructList(mIntContainer, sizeof(elements) / sizeof(int), elements);
	MERGE_SORT(mIntContainer, mIntLessEqComp);
	CHECK_ORDER(mIntContainer, sizeof(elements) / sizeof(int), mIntLessEqComp);
}

TEST_F(MSortTest, IntDuplicateGreater_06)
{
	int elements[] = { 0, 1, 3, 3, 1, 5 };
	ConstructList(mIntContainer, sizeof(elements) / sizeof(int), elements);
	MERGE_SORT(mIntContainer, mIntGreaterEqComp);
	CHECK_ORDER(mIntContainer, sizeof(elements) / sizeof(int), mIntGreaterEqComp);
}

#if RUN_TIME_TESTS

TEST_F(MSortTest, IntLarge10000Less_07)
{
	const int NUMBER_OF_ITEMS = 10000;
	ConstructList(mIntContainer, NUMBER_OF_ITEMS);
	MERGE_SORT(mIntContainer, mIntLessEqComp);
	CHECK_ORDER(mIntContainer, NUMBER_OF_ITEMS, mIntLessEqComp);
}

TEST_F(MSortTest, IntLarge100000Less_08)
{
	const int NUMBER_OF_ITEMS = 100000;
	ConstructList(mIntContainer, NUMBER_OF_ITEMS);
	MERGE_SORT(mIntContainer, mIntLessEqComp);
	CHECK_ORDER(mIntContainer, NUMBER_OF_ITEMS, mIntLessEqComp);
}

TEST_F(MSortTest, IntLarge1000000Less_09)
{
	const int NUMBER_OF_ITEMS = 1000000;
	ConstructList(mIntContainer, NUMBER_OF_ITEMS);
	MERGE_SORT(mIntContainer, mIntLessEqComp);
	CHECK_ORDER(mIntContainer, NUMBER_OF_ITEMS, mIntLessEqComp);
}

TEST_F(MSortTest, IntLarge10000Greater_10)
{
	const int NUMBER_OF_ITEMS = 10000;
	ConstructList(mIntContainer, NUMBER_OF_ITEMS);
	MERGE_SORT(mIntContainer, mIntGreaterEqComp);
	CHECK_ORDER(mIntContainer, NUMBER_OF_ITEMS, mIntGreaterEqComp);
}

TEST_F(MSortTest, IntLarge100000Greater_11)
{
	const int NUMBER_OF_ITEMS = 100000;
	ConstructList(mIntContainer, NUMBER_OF_ITEMS);
	MERGE_SORT(mIntContainer, mIntGreaterEqComp);
	CHECK_ORDER(mIntContainer, NUMBER_OF_ITEMS, mIntGreaterEqComp);
}

TEST_F(MSortTest, IntLarge1000000Greater_12)
{
	const int NUMBER_OF_ITEMS = 1000000;
	ConstructList(mIntContainer, NUMBER_OF_ITEMS);
	MERGE_SORT(mIntContainer, mIntGreaterEqComp);
	CHECK_ORDER(mIntContainer, NUMBER_OF_ITEMS, mIntGreaterEqComp);
}

#endif

/*
	These are tests for strings. In total there are 6 tests for strings. They are:
	13. StringInOrderLess -- Checks on list with strings already in increasing order, looking for increasing.
	14. StringInOrderGreater -- Checks on list with strings already inserted in decreasing order, looking for decreasing.
	15. StringScrambledLess -- Checks on list with scrambled strings order, looking for increasing.
	16. StringScrambledGreater -- Checks on list with scrambled strings order, looking for decreasing.
	17. StringDuplicateLess -- Checks on list with scrambled string order and duplicates, looking for increasing.
	18. StringDuplicateGreater -- Checks on list with scrambled string order and duplicates, looking for increasing.
*/

TEST_F(MSortTest, StringInOrderLess_13)
{
	std::string elements[] = { "Aaron", "Betty", "Carla", "David", "Esther" };
	ConstructList(mStringContainer, sizeof(elements) / sizeof(std::string), elements);
	MERGE_SORT(mStringContainer, mStringLessComp);
	CHECK_ORDER(mStringContainer, sizeof(elements) / sizeof(std::string), mStringLessComp);
}


TEST_F(MSortTest, StringInOrderGreater_14)
{
	std::string elements[] = { "Esther", "David", "Carla", "Betty", "Aaron" };
	ConstructList(mStringContainer, sizeof(elements) / sizeof(std::string), elements);
	MERGE_SORT(mStringContainer, mStringGreaterComp);
	CHECK_ORDER(mStringContainer, sizeof(elements) / sizeof(std::string), mStringGreaterComp);
}

TEST_F(MSortTest, StringScrambledLess_15)
{
	std::string elements[] = { "Betty", "Aaron", "Esther", "Carla", "David" };
	ConstructList(mStringContainer, sizeof(elements) / sizeof(std::string), elements);
	MERGE_SORT(mStringContainer, mStringLessComp);
	CHECK_ORDER(mStringContainer, sizeof(elements) / sizeof(std::string), mStringLessComp);
}

TEST_F(MSortTest, StringScrambledGreater_16)
{
	std::string elements[] = { "Betty", "Aaron", "Esther", "Carla", "David" };
	ConstructList(mStringContainer, sizeof(elements) / sizeof(std::string), elements);
	MERGE_SORT(mStringContainer, mStringGreaterComp);
	CHECK_ORDER(mStringContainer, sizeof(elements) / sizeof(std::string), mStringGreaterComp);
}

TEST_F(MSortTest, StringDuplicateLess_17)
{
	std::string elements[] = { "Betty", "Aaron", "Esther", "Betty", "Aaron" };
	ConstructList(mStringContainer, sizeof(elements) / sizeof(std::string), elements);
	MERGE_SORT(mStringContainer, mStringLessEqComp);
	CHECK_ORDER(mStringContainer, sizeof(elements) / sizeof(std::string), mStringLessEqComp);
}

TEST_F(MSortTest, StringDuplicateGreater_18)
{
	std::string elements[] = { "Betty", "Aaron", "Esther", "Betty", "Aaron" };
	ConstructList(mStringContainer, sizeof(elements) / sizeof(std::string), elements);
	MERGE_SORT(mStringContainer, mStringGreaterEqComp);
	CHECK_ORDER(mStringContainer, sizeof(elements) / sizeof(std::string), mStringGreaterEqComp);
}

/*
	These are tests for pairs. In total there are 6 tests for pairs. They are:
	19. PairInOrderLess -- Checks on list with pairs already in increasing order, looking for increasing.
	20. PairInOrderGreater -- Checks on list with pairs already inserted in decreasing order, looking for decreasing.
	21. PairScrambledLess -- Checks on list with scrambled pairs order, looking for increasing.
	22. PairScrambledGreater -- Checks on list with scrambled pairs order, looking for decreasing.
	23. PairDuplicateLess -- Checks on list with scrambled pairs order and duplicates, looking for increasing.
	24. PairDuplicateGreater -- Checks on list with scrambled pairs order and duplicates, looking for increasing.
*/

TEST_F(MSortTest, PairInOrderLess_19)
{
	std::pair<std::string, int> elements[] = { { "Aaron", 0 }, { "Betty", 1 }, { "Carla", 2 }, { "David", 3 }, { "Esther", 4 } };
	ConstructList(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), elements);
	MERGE_SORT(mStringIntPairContainer, mStringIntPairLessComp);
	CHECK_ORDER(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), mStringIntPairLessComp);
}

TEST_F(MSortTest, PairInOrderGreater_20)
{
	std::pair<std::string, int> elements[] = { { "Esther", 0 }, { "David", 1 }, { "Carla", 2 }, { "Betty", 3 }, { "Aaron", 4 } };
	ConstructList(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), elements);
	MERGE_SORT(mStringIntPairContainer, mStringIntPairGreaterComp);
	CHECK_ORDER(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), mStringIntPairGreaterComp);
}

TEST_F(MSortTest, PairScrambledLess_21)
{
	std::pair<std::string, int> elements[] = { { "Betty", 0 }, { "Aaron", 1 }, { "Esther", 2 }, { "David", 3 }, { "Carla", 4 } };
	ConstructList(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), elements);
	MERGE_SORT(mStringIntPairContainer, mStringIntPairLessComp);
	CHECK_ORDER(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), mStringIntPairLessComp);
}

TEST_F(MSortTest, PairScrambledGreater_22)
{
	std::pair<std::string, int> elements[] = { { "Betty", 0 }, { "Aaron", 1 }, { "Esther", 2 }, { "David", 3 }, { "Carla", 4 } };
	ConstructList(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), elements);
	MERGE_SORT(mStringIntPairContainer, mStringIntPairGreaterComp);
	CHECK_ORDER(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), mStringIntPairGreaterComp);
}

TEST_F(MSortTest, PairDuplicateLess_23)
{
	std::pair<std::string, int> elements[] = { { "Betty", 0 }, { "Aaron", 1 }, { "Esther", 2 }, { "Betty", 3 }, { "Aaron", 4 } };
	ConstructList(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), elements);
	MERGE_SORT(mStringIntPairContainer, mStringIntPairLessEqComp);
	CHECK_ORDER(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), mStringIntPairLessEqComp);
}

TEST_F(MSortTest, PairDuplicateGreater_24)
{
	std::pair<std::string, int> elements[] = { { "Betty", 0 }, { "Aaron", 1 }, { "Esther", 2 }, { "Betty", 3 }, { "Aaron", 4 } };
	ConstructList(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), elements);
	MERGE_SORT(mStringIntPairContainer, mStringIntPairGreaterEqComp);
	CHECK_ORDER(mStringIntPairContainer, sizeof(elements) / sizeof(std::pair<std::string, int>), mStringIntPairGreaterEqComp);
}
