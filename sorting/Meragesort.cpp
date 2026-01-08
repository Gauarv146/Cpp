#include <iostream>
using namespace std;

class Solution {
public:
    // Function to merge two sorted halves
    void merge(int arr[], int low, int mid, int high) {
        int temp[high - low + 1];   // Temporary array
        int left = low;
        int right = mid + 1;
        int k = 0;

        // Merge the two halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp[k++] = arr[left++];
            else
                temp[k++] = arr[right++];
        }

        // Copy remaining elements of left half
        while (left <= mid)
            temp[k++] = arr[left++];

        // Copy remaining elements of right half
        while (right <= high)
            temp[k++] = arr[right++];

        // Copy temp array back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    // Recursive Merge Sort
    void mergeSort(int arr[], int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
};

int main() {
    int arr[] = {5, 2, 8, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution sol;
    sol.mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
