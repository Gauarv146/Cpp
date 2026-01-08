// Optimal

#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int xorAll = 0;

    // XOR all numbers from 1 to n
    for(int i = 1; i <= n; i++) {
        xorAll ^= i;
    }

    // XOR all elements in the array
    for(int i = 0; i < n - 1; i++) {
        xorAll ^= arr[i];
    }

    return xorAll;
}

int main() {
    int arr[] = {1, 2, 4, 5};
    int n = 5;

    cout << "Missing number is: " << findMissing(arr, n);
    return 0;
}
