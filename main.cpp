#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "binPacking.hpp"

// Test that both algorithms correctly pack a small set of items into the optimal number of bins (expected: 2 bins)
TEST(binPackingTest, SimpleTest) {
    std::vector<int> items = {4, 8, 1, 4, 2, 1};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 2);
    EXPECT_EQ(resultBFD, 2);
}

// Verify that both algorithms use exactly 3 bins for this specific set of items
TEST(binPackingTest, ThreeBins) {
    std::vector<int> items = {8, 8, 4, 4, 2, 2};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 3);
    EXPECT_EQ(resultBFD, 3);
}

// Verify that both algorithms use exactly 4 bins for this specific set of items
TEST(binPackingTest, FourBins) {
    std::vector<int> items = {5, 7, 6, 2, 8, 4, 3};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 4);
    EXPECT_EQ(resultBFD, 4);
}

// Test edge case where the item list is empty; expect 0 bins to be used
TEST(binPackingTest, EmptyItems) {
    std::vector<int> items = {};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 0);
    EXPECT_EQ(resultBFD, 0);
}

// Test that a single item is correctly placed in one bin
TEST(binPackingTest, SingleItem) {
    std::vector<int> items = {5};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 1);
    EXPECT_EQ(resultBFD, 1);
}

// Test that two items are placed in a single bin when there is extra space left
TEST(binPackingTest, SingleBinWithExtraSpace) {
    std::vector<int> items = {5, 5};
    int binSize = 11;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 1);
    EXPECT_EQ(resultBFD, 1);
}

// Test that two items are placed in separate bins when one bin cannot accommodate both
TEST(binPackingTest, SingleBinWithNoSpace) {
    std::vector<int> items = {5, 5};
    int binSize = 9;
    int resultFFD= firstFitDecreasing(items, binSize);
    int resultBFD= bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 2);
    EXPECT_EQ(resultBFD, 2);
}

// Test that a single item exactly equal to bin size is placed in one bin
TEST(binPackingTest, SingleBinWithJustEnoughSpace) {
    std::vector<int> items = {10};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 1);
    EXPECT_EQ(resultBFD, 1);
}

// Test that two items perfectly fill a single bin
TEST(binPackingTest, SingleBinFitMultiple) {
    std::vector<int> items = {5, 5};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 1);
    EXPECT_EQ(resultBFD, 1);
}

// Test behavior when a single item exceeds bin capacity; expect -1 to indicate unsolvable case
TEST(binPackingTest, SingleItemWithNoSpace) {
    std::vector<int> items = {10};
    int binSize = 9;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, -1);
    EXPECT_EQ(resultBFD, -1);
}

// Test that both algorithms pack a large number of small items efficiently into 100 bins
TEST(binPackingTest, ManySmallItems) {
    std::vector<int> items(1000, 1);  // 1000 items of size 1
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 100);  // Expect 100 bins
    EXPECT_EQ(resultBFD, 100);
}

// Test that both algorithms produce the same result with a mixture of small and large items
TEST(binPackingTest, MixedSmallAndLargeItems) {
    std::vector<int> items = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, resultBFD);  // Expect both algorithms to use the same number of bins
}

// Stress test to verify that both algorithms handle a large input efficiently
TEST(binPackingTest, LargeNumberOfItems) {
    std::vector<int> items(10000, 2);  // 10000 items of size 2
    int binSize = 10;
    EXPECT_EQ(firstFitDecreasing(items, binSize), 2000);  // Expect 2000 bins
    EXPECT_EQ(bestFitDecreasing(items, binSize), 2000);   // Expect 2000 bins
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
