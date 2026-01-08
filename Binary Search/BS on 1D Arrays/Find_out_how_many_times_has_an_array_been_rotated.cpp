//Optimal
#include <iostream>
#include <vector>
using namespace std;

int countRotations(vector<int>& arr) {
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high) {

        // Case 1: Array is already sorted
        if (arr[low] <= arr[high]) {
            return low;
        }

        int mid = low + (high - low) / 2;

        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;

        // Case 2: Mid is the minimum element
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
            return mid;
        }

        // Case 3: Left half is sorted, pivot is in right half
        if (arr[low] <= arr[mid]) {
            low = mid + 1;
        }
        // Case 4: Right half is sorted, pivot is in left half
        else {
            high = mid - 1;
        }
    }

    return 0;
}

int main() {
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    cout << "Array is rotated " << countRotations(arr) << " times";
    return 0;
}
