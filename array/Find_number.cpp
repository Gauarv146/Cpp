// Find the number that appears once and other numbers twice

// Optimal
#include <iostream>
using namespace std;

int findSingle(int arr[], int n) {
    int xr = 0;

    for (int i = 0; i < n; i++) {
        xr = xr ^ arr[i];
    }

    return xr;
}

int main() {
    int arr[] = {4, 1, 2, 1, 2};
    int n = 5;

    cout << "Single number: " << findSingle(arr, n);
    return 0;
}
