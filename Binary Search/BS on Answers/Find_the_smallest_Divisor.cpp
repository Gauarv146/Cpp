//Optimal
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Helper function to compute sum for a given divisor
    int computeSum(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + divisor - 1) / divisor;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int sum = computeSum(nums, mid);

            if (sum <= threshold) {
                ans = mid;          // mid is a valid divisor
                high = mid - 1;     // try to find smaller divisor
            } else {
                low = mid + 1;      // divisor too small → increase
            }
        }

        return ans;
    }
};
