//Opitmal Approach: Using XOR
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

    int setBit = xr & -xr;

    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] & setBit)
            x ^= arr[i];
        else
            y ^= arr[i];

        if ((i + 1) & setBit)
            x ^= (i + 1);
        else
            y ^= (i + 1);
    }

    int countX = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            countX++;
    }

    int repeating, missing;
    if (countX == 2) {
        repeating = x;
        missing = y;
    } else {
        repeating = y;
        missing = x;
    }

    cout << "Repeating number: " << repeating << endl;
    cout << "Missing number: " << missing << endl;

    return 0;
}
