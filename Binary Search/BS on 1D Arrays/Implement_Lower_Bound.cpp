//Optimal
#include <bits/stdc++.h>
using namespace std;

int lowerBoundOptimal(vector<int>& arr, int x) {
    auto it = lower_bound(arr.begin(), arr.end(), x);
    return it - arr.begin();   // index
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 7};
    int x = 4;

    cout << "Lower Bound Index: " << lowerBoundOptimal(arr, x);
    return 0;
}
