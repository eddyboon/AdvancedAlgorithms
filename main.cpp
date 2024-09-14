#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "binPacking.hpp"

TEST(binPackingTest, BaseTest) {
    std::vector<int> items = {4, 8, 1, 4, 2, 1};
    int binSize = 10;
    int result = binPacking(items, binSize);
    EXPECT_EQ(result, 2);
}

TEST(binPackingTest, FourBins) {
    std::vector<int> items = {5, 7, 6, 2, 8, 4, 3};
    int binSize = 10;
    int result = binPacking(items, binSize);
    EXPECT_EQ(result, 4);
}

TEST(binPackingTest, AnotherFourBins) {
    std::vector<int> items = {9, 9, 6, 6, 4, 4};
    int binSize = 10;
    int result = binPacking(items, binSize);
    EXPECT_EQ(result, 4);
}

TEST(binPackingTest, ThreeBins) {
    std::vector<int> items = {8, 8, 4, 4, 2, 2};
    int binSize = 10;
    int result = binPacking(items, binSize);
    EXPECT_EQ(result, 3);
}

TEST(binPackingTest, EmptyItems) {
    std::vector<int> items = {};
    int binSize = 10;
    int result = binPacking(items, binSize);
    EXPECT_EQ(result, 0);
}

TEST(binPackingTest, SingleItem) {
    std::vector<int> items = {5};
    int binSize = 10;
    int result = binPacking(items, binSize);
    EXPECT_EQ(result, 1);
}

TEST(binPackingTest, SingleBinWithExtraSpace) {
    std::vector<int> items = {5, 5};
    int binSize = 11;
    int result = binPacking(items, binSize);
    EXPECT_EQ(result, 1);
}

TEST(binPackingTest, SingleBinWithNoSpace) {
    std::vector<int> items = {5, 5};
    int binSize = 9;
    int result = binPacking(items, binSize);
    EXPECT_EQ(result, 2);
}

TEST(binPackingTest, SingleItemWithJustEnoughSpace) {
    std::vector<int> items = {10};
    int binSize = 10;
    int result = binPacking(items, binSize);
    EXPECT_EQ(result, 1);
}

TEST(binPackingTest, SingleBin) {
    std::vector<int> items = {5, 5};
    int binSize = 10;
    int result = binPacking(items, binSize);
    EXPECT_EQ(result, 1);
}

TEST(binPackingTest, SingleItemWithNoSpace) {
    std::vector<int> items = {10};
    int binSize = 9;
    int result = binPacking(items, binSize);
    EXPECT_EQ(result, -1);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
