// Optimal Approach 
#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumK(int arr[], int n, int k) {
    unordered_map<int, int> prefixIndex;
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: subarray from index 0 to i
        if (prefixSum == k) {
            maxLen = i + 1;
        }

        // Case 2: subarray ending at i with sum k
        if (prefixIndex.find(prefixSum - k) != prefixIndex.end()) {
            maxLen = max(maxLen, i - prefixIndex[prefixSum - k]);
        }

        // Store first occurrence only
        if (prefixIndex.find(prefixSum) == prefixIndex.end()) {
            prefixIndex[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {1, -1, 5, -2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << longestSubarrayWithSumK(arr, n, k);
    return 0;
}