#include "binPacking.hpp"

int binPacking(std::vector<int> &items, int binSize) {
    std::sort(items.begin(), items.end(), std::greater<int>());
    std::vector<int> bins;

    for (int item : items) {
        bool placed = false;

        for (int &bin : bins) {
            if (bin >= item) {
                bin -= item;
                placed = true;
                break;
            }
        }

        if (!placed) {
            bins.push_back(binSize - item);
        }
    }

    return bins.size();
}
