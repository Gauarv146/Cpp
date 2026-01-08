// Optimal Code
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int>& arr, int K) {
    int n = arr.size();

    unordered_map<int, int> mp;  // prefixSum -> first index
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        // Step 1: Add current element to prefix sum
        prefixSum += arr[i];

        // Step 2: If entire subarray [0..i] sums to K
        if (prefixSum == K) {
            maxLen = max(maxLen, i + 1);
        }

        // Step 3: Check if (prefixSum - K) exists
        if (mp.find(prefixSum - K) != mp.end()) {
            int length = i - mp[prefixSum - K];
            maxLen = max(maxLen, length);
        }

        // Step 4: Store prefixSum only if not present
        if (mp.find(prefixSum) == mp.end()) {
            mp[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, -1, 5, -2, 3};
    int K = 3;

    cout << longestSubarrayWithSumK(arr, K);
    return 0;
}