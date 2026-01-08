//Optimal
#include <bits/stdc++.h>
using namespace std;

int upperBoundOptimal(vector<int>& arr, int x) {
    return upper_bound(arr.begin(), arr.end(), x) - arr.begin();
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 6};
    int x = 4;

    cout << upperBoundOptimal(arr, x);
    return 0;
}
