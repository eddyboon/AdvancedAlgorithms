#ifndef BINPACKING_HPP
#define BINPACKING_HPP

#include <vector>
#include <algorithm>
#include  <numeric>

int firstFitDecreasing(std::vector<int> &items, int binSize);

int bestFitDecreasing(std::vector<int> &items, int binSize);

#endif
