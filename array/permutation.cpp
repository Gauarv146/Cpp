// optimal
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    // 1) Find the first index 'i' from the right such that nums[i] < nums[i+1]
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // 2) If such index exists, find 'j' from the right such that nums[j] > nums[i]
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // 3) Reverse the suffix starting at i+1
    reverse(nums.begin() + i + 1, nums.end());
}
