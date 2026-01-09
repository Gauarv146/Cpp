//Optimal
#include <bits/stdc++.h>
using namespace std;

int countSmallerEqual(vector<vector<int>>& matrix, int mid) {
    int cnt = 0;
    for (auto &row : matrix) {
        cnt += upper_bound(row.begin(), row.end(), mid) - row.begin();
    }
    return cnt;
}

int findMedian(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    int low = INT_MAX, high = INT_MIN;

    // Tight bounds from matrix itself
    for (int i = 0; i < r; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][c - 1]);
    }

    int req = (r * c) / 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int cnt = countSmallerEqual(matrix, mid);

        if (cnt <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
