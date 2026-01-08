//Optimal
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    cout << searchInsert(nums, target);
    return 0;
}
