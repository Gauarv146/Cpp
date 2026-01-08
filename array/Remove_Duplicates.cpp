#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;

    int i = 0;  // index of last unique element

    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1; // new length
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int newLength = removeDuplicates(arr, n);

    for (int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
