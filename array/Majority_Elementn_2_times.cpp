//Optimal
#include <iostream>
using namespace std;

int majorityElement(int arr[], int n) {
    int count = 0;
    int candidate = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
        else if (arr[i] == candidate) {
            count++;
        }
        else {
            count--;
        }
    }
    return candidate;
}

int main() {
    int arr[] = {2, 2, 1, 1, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << majorityElement(arr, n);
    return 0;
}
