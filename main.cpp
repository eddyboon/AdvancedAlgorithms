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

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
