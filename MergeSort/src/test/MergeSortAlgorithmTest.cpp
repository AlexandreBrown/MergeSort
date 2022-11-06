#include <gtest/gtest.h>
#include "../main/MergeSortAlgorithm.h"

using namespace std;

namespace {
	class MergeSortAlgorithmTest : public testing::Test {

		public:
			MergeSortAlgorithm sortAlgorithm;

			void SetUp() override {
				sortAlgorithm = MergeSortAlgorithm();
			}
	};
}

TEST_F(MergeSortAlgorithmTest, sorts_elements_for_empty_arrays) {
	auto a = vector<int>{};

	sortAlgorithm.sort(a);

	auto expected = vector<int>{};
	ASSERT_EQ(expected, a);
}

TEST_F(MergeSortAlgorithmTest, sorts_elements_for_arrays_with_duplicates) {
	auto a = vector<int>{5, 6, 2, 2, 0, 1, 128, 66, 69, 69};

	sortAlgorithm.sort(a);

	auto expected = vector<int>{0, 1, 2, 2, 5, 6, 66, 69, 69, 128};
	ASSERT_EQ(expected, a);
}

TEST_F(MergeSortAlgorithmTest, sorts_elements_for_small_arrays) {
	auto a = vector<int>{3, 0, 1, 10, 5};

	sortAlgorithm.sort(a);

	auto expected = vector<int>{0, 1, 3, 5, 10};
	ASSERT_EQ(expected, a);
}

TEST_F(MergeSortAlgorithmTest, sorts_elements_for_medium_arrays) {
	auto a = vector<int>{5, 10, 15, 894, 84654, 1, 565, 65, 654, 6548, 111, 11, 0};

	sortAlgorithm.sort(a);

	auto expected = vector<int>{0, 1, 5, 10, 11, 15, 65, 111, 565, 654, 894, 6548, 84654};
	ASSERT_EQ(expected, a);
}

TEST_F(MergeSortAlgorithmTest, sorts_elements_for_large_arrays) {
	auto a = vector<int>{2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1, 0, -1, 155, 10000, 129, 257, 20000, 5, 40, 20, 6, 7};

	sortAlgorithm.sort(a);

	auto expected = vector<int>{-1, 0, 1, 2, 4, 5, 6, 7, 8, 16, 20, 32, 40, 64, 128, 129, 155, 256, 257, 512, 1024, 2048, 10000, 20000};
	ASSERT_EQ(expected, a);
}
