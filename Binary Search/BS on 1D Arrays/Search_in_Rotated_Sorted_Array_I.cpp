//Optimal
#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Case 1: target found
        if (nums[mid] == target)
            return mid;

        // Case 2: left half is sorted
        if (nums[low] <= nums[mid]) {
            // target lies in left sorted half
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Case 3: right half is sorted
        else {
            // target lies in right sorted half
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << search(nums, target) << endl;
    return 0;
}
