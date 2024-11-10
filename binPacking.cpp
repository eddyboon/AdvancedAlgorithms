#include "binPacking.hpp"

#include <numeric>

int firstFitDecreasing(std::vector<int> &items, int binSize) {
    // Sort items in descending order for more efficient packing
    std::sort(items.begin(), items.end(), std::greater<int>());
    std::vector<int> bins;  // Vector to store remaining space in each bin

    // Check for any item that exceeds the bin size; if found, return -1 (unsolvable case)
    for (int item : items) {
        if (item > binSize) {
            return -1;
        }
    }

    // Place each item in the first bin that has enough space
    for (int item : items) {
        bool placed = false;

        // Try to fit the item into an existing bin
        for (int &bin : bins) {
            if (bin >= item) {  // Check if the current bin can accommodate the item
                bin -= item;    // Reduce the available space in the bin
                placed = true;
                break;          // Exit loop after placing item
            }
        }

        // If no existing bin could accommodate the item, create a new bin
        if (!placed) {
            bins.push_back(binSize - item);  // Initialise new bin with remaining space
        }
    }

    return bins.size();  // Return the total number of bins used
}

int bestFitDecreasing(std::vector<int> &items, int binSize) {
    // Sort items in descending order for more efficient packing
    std::sort(items.begin(), items.end(), std::greater<int>());
    std::vector<int> bins;  // Vector to store remaining space in each bin

    // Check for any item that exceeds the bin size; if found, return -1 (unsolvable case)
    for (int item : items) {
        if (item > binSize) {
            return -1;
        }
    }

    // Place each item in the bin with the least remaining space that can accommodate it
    for(int item : items) {
        bool foundBin = false;

        int bestBinIndex = -1;     // Index of the best-fitting bin
        int minSpaceLeft = binSize + 1;  // Track the minimum remaining space after placing the item

        // Find the best bin that has enough space to accommodate the item
        for(int i = 0; i < bins.size(); ++i) {
            if(bins[i] >= item && bins[i] - item < minSpaceLeft) {
                bestBinIndex = i;                   // Update index of the best bin found so far
                minSpaceLeft = bins[i] - item;      // Update minimum space left after placement
            }
        }

        // Place item in the best-fitting bin, if one is found
        if (bestBinIndex != -1) {
            bins[bestBinIndex] -= item;  // Reduce the available space in the selected bin
            foundBin = true;
        }

        // If no suitable bin was found, create a new bin
        if (!foundBin) {
            bins.push_back(binSize - item);  // Initialise new bin with remaining space
        }
    }

    return bins.size();  // Return the total number of bins used
}


