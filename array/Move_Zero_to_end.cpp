// Optimal

#include <iostream>
using namespace std;

void moveZeroes(int arr[], int n) {
    int j = 0; // position for next non-zero element

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
    int arr[] = {1, 0, 2, 0, 3, 0, 4};
    int n = 7;

    moveZeroes(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
