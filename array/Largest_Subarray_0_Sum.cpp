//Optimal
#include <iostream>
#include <unordered_map>
using namespace std;

int largestZeroSumSubarray(int arr[], int n) {
    unordered_map<int, int> firstIndex;
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        if (firstIndex.find(prefixSum) != firstIndex.end()) {
            maxLen = max(maxLen, i - firstIndex[prefixSum]);
        } else {
            firstIndex[prefixSum] = i;
        }
    }
    return maxLen;
}

int main() {
    int arr[] = {9, -3, 3, -1, 6, -5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << largestZeroSumSubarray(arr, n);
    return 0;
}
