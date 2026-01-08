//Optimal
#include <bits/stdc++.h>
using namespace std;

pair<int,int> floorCeil(int arr[], int n, int x) {
    int floorVal = -1, ceilVal = -1;

    int idx = lower_bound(arr, arr + n, x) - arr;

    // Ceil
    if (idx < n) {
        ceilVal = arr[idx];
    }

    // Floor
    if (idx > 0) {
        floorVal = arr[idx - 1];
    }

    return {floorVal, ceilVal};
}
