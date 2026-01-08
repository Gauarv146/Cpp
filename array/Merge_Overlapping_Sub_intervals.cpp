//optimal
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> intervals = {
        {1,3}, {2,6}, {8,10}, {15,18}
    };

    // Step 1: Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    int k = 0;  // Index of last merged interval

    // Step 2: Traverse from second interval
    for (int i = 1; i < intervals.size(); i++) {

        // If overlapping with last merged interval
        if (intervals[i][0] <= intervals[k][1]) {
            intervals[k][1] = max(intervals[k][1], intervals[i][1]);
        }
        // If no overlap, move k forward
        else {
            k++;
            intervals[k] = intervals[i];
        }
    }

    // Output merged intervals
    for (int i = 0; i <= k; i++) {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "] ";
    }

    return 0;
}
