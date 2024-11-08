#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "binPacking.hpp"

// Simple test on small input
TEST(binPackingTest, SimpleTest) {
    std::vector<int> items = {4, 8, 1, 4, 2, 1};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 2);
    EXPECT_EQ(resultBFD, 2);
}

// Test exact result of 3 bins is returned on small input of items
TEST(binPackingTest, ThreeBins) {
    std::vector<int> items = {8, 8, 4, 4, 2, 2};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 3);
    EXPECT_EQ(resultBFD, 3);
}

// Test exact result of 4 bins is returned on small input of items
TEST(binPackingTest, FourBins) {
    std::vector<int> items = {5, 7, 6, 2, 8, 4, 3};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 4);
    EXPECT_EQ(resultBFD, 4);
}

// Test empty items edge case
TEST(binPackingTest, EmptyItems) {
    std::vector<int> items = {};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 0);
    EXPECT_EQ(resultBFD, 0);
}

// Test one item is correctly assigned to bin
TEST(binPackingTest, SingleItem) {
    std::vector<int> items = {5};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 1);
    EXPECT_EQ(resultBFD, 1);
}

// Test items correctly assigned to bin that can accommodate multiple items
TEST(binPackingTest, SingleBinWithExtraSpace) {
    std::vector<int> items = {5, 5};
    int binSize = 11;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 1);
    EXPECT_EQ(resultBFD, 1);
}

// Test new bin is correctly created when bin is unable to accommodate multiple items
TEST(binPackingTest, SingleBinWithNoSpace) {
    std::vector<int> items = {5, 5};
    int binSize = 9;
    int resultFFD= firstFitDecreasing(items, binSize);
    int resultBFD= bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 2);
    EXPECT_EQ(resultBFD, 2);
}

// Test item correctly assigned to bin of matching capacity
TEST(binPackingTest, SingleBinWithJustEnoughSpace) {
    std::vector<int> items = {10};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 1);
    EXPECT_EQ(resultBFD, 1);
}

// Test multiple items correctly assigned to bin with the exact amount of accommodating space
TEST(binPackingTest, SingleBinFitMultiple) {
    std::vector<int> items = {5, 5};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, 1);
    EXPECT_EQ(resultBFD, 1);
}

// Test for correct behaviour when bin is unable to accommodate item
TEST(binPackingTest, SingleItemWithNoSpace) {
    std::vector<int> items = {10};
    int binSize = 9;

    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);

    EXPECT_EQ(resultFFD, -1);
    EXPECT_EQ(resultBFD, -1);
}


// Test FFD correctly assigns many small items to bins
TEST(binPackingTest, ManySmallItems) {
    std::vector<int> items(1000, 1);  // 1000 items of size 1
    int binSize = 10;

    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);

    EXPECT_EQ(resultFFD, 100);  // Should fit into 100 bins
    EXPECT_EQ(resultBFD, 100);
}

// Test both algorithms return identical result when given items of varying sizes
TEST(binPackingTest, MixedSmallAndLargeItems) {
    std::vector<int> items = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int binSize = 10;
    int resultFFD = firstFitDecreasing(items, binSize);
    int resultBFD = bestFitDecreasing(items, binSize);
    EXPECT_EQ(resultFFD, resultBFD);  // Expect a similar number of bins for both
}

// Stress test to ensure a result is returned with a large input of items
TEST(binPackingTest, LargeNumberOfItems) {
    std::vector<int> items(10000, 2);  // 10000 items of size 2
    int binSize = 10;
    EXPECT_EQ(firstFitDecreasing(items, binSize), 2000);
    EXPECT_EQ(bestFitDecreasing(items, binSize), 2000);
}


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
