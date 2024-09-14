#include "binPacking.hpp"

int binPacking(std::vector<int> &items, int binSize) {
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
