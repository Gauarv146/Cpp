//Optimal
#include <bits/stdc++.h>
using namespace std;

bool canSplit(vector<int>& nums, int k, long long maxAllowed) {

    long long currentSum = 0;
    int subarrays = 1;

    for (int i = 0; i < nums.size(); i++) {

        if (currentSum + nums[i] <= maxAllowed) {
            currentSum += nums[i];
        } else {
            subarrays++;
            currentSum = nums[i];

            if (subarrays > k) return false;
        }
    }

    return true;
}

int splitArray(vector<int>& nums, int k) {

    long long low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0LL);
    long long answer = high;

    while (low <= high) {

        long long mid = low + (high - low) / 2;

        if (canSplit(nums, k, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}
