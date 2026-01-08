// Optimal
#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(sum == target)
            return true;
        else if(sum < target)
            left++;
        else
            right--;
    }
    return false;
}

int main() {
    vector<int> arr = {2, 7, 11, 15}; // must be sorted
    int target = 9;

    cout << twoSum(arr, target);
    return 0;
}