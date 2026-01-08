
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    sort(arr.begin(), arr.end());

    int longest = 1;
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            continue;
        }
        else if (arr[i] == arr[i - 1] + 1) {
            count++;
        }
        else {
            count = 1;
        }
        longest = max(longest, count);
    }

    return longest;
}
