#include "binPacking.hpp"

#include <numeric>

int firstFitDecreasing(std::vector<int> &items, int binSize) {
    // Sort items in descending order
    std::sort(items.begin(), items.end(), std::greater<int>());
    std::vector<int> bins;

    // Ensure all items can fit in a bin
    for (int item : items) {
        if (item > binSize) {
            return -1;
        }
    }

    for (int item : items) {
        bool placed = false;

        // Try to place the item in an existing bin and decrease bin size if placed
        for (int &bin : bins) {
            if (bin >= item) {
                bin -= item;
                placed = true;
                break;
            }
        }

        // Create new bin for new item and decrease bin size
        if (!placed) {
            bins.push_back(binSize - item);
        }
    }

    return bins.size();
}

int bestFitDecreasing(std::vector<int> &items, int binSize) {

    // Sort in decreasing order
    std::sort(items.begin(), items.end(), std::greater<int>());
    std::vector<int> bins;

    for(int item : items) {
        bool foundBin = false;

        int bestBinIndex = -1;
        int minSpaceLeft = binSize + 1;

        for(int i = 0; i < bins.size(); ++i) {
            if(bins[i] >= item && bins[i] - item < minSpaceLeft) {
                bestBinIndex = i;
                minSpaceLeft = bins[i] - item;
            }
        }

        // Place item in the best fitting bin, if available
        if (bestBinIndex != -1) {
            bins[bestBinIndex] -= item;
            foundBin = true;
        }

        // If no suitable bin was found, create a new bin
        if (!foundBin) {
            bins.push_back(binSize - item);
        }
    }

    return bins.size();
}

