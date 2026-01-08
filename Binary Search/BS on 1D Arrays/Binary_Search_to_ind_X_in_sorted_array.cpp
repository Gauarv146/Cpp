//Optimal Code
#include <bits/stdc++.h>
using namespace std;

int searchElement(vector<int>& arr, int x) {
    auto it = lower_bound(arr.begin(), arr.end(), x);

    if (it != arr.end() && *it == x) {
        return it - arr.begin();
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int x = 10;

    int index = searchElement(arr, x);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
