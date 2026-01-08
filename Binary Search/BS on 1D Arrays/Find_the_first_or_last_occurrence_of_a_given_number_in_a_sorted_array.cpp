//Optimal
#include <bits/stdc++.h>
using namespace std;

pair<int, int> firstAndLastOccurrence(vector<int>& arr, int x) {
    int n = arr.size();

    // ---------- First Occurrence (Lower Bound) ----------
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            if (arr[mid] == x)
                first = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // If element not found at all
    if (first == -1)
        return {-1, -1};

    // ---------- Last Occurrence (Upper Bound - 1) ----------
    low = 0;
    high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            if (arr[mid] == x)
                last = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return {first, last};
}
