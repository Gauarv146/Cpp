// Optimal
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = INT_MIN;
    int currentSum = 0;

    int start = 0;        // final subarray start
    int end = 0;          // final subarray end
    int tempStart = 0;    // temporary start index

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << "Subarray: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
