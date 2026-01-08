//Optimal
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // Peak lies on the right side
            low = mid + 1;
        } else {
            // Peak lies on the left side or at mid
            high = mid;
        }
    }

    // low == high is the peak index
    return low;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    int peakIndex = findPeakElement(nums);

    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak element value: " << nums[peakIndex] << endl;

    return 0;
}
