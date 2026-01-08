// Optimal
#include <iostream>
using namespace std;

void printLeaders(int arr[], int n) {

    int maxFromRight = arr[n - 1];
    cout << maxFromRight << " ";

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            maxFromRight = arr[i];
            cout << arr[i] << " ";
        }
    }
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printLeaders(arr, n);

    return 0;
}
