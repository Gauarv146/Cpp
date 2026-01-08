//Optimal
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {3, 1, 2, 5, 3};
    int n = arr.size();

    int xr = 0;

    for (int i = 0; i < n; i++) {
        xr ^= arr[i];
        xr ^= (i + 1);
    }

    int bit = xr & -xr;

    int zero = 0, one = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] & bit)
            one ^= arr[i];
        else
            zero ^= arr[i];

        if ((i + 1) & bit)
            one ^= (i + 1);
        else
            zero ^= (i + 1);
    }

    int repeating, missing;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == zero)
            count++;
    }

    if (count == 2) {
        repeating = zero;
        missing = one;
    } else {
        repeating = one;
        missing = zero;
    }

    cout << "Repeating number: " << repeating << endl;
    cout << "Missing number: " << missing << endl;

    return 0;
}
