//Optimal
#include <bits/stdc++.h>
using namespace std;

vector<int> zFunction(string s) {
    int n = s.length();
    vector<int> Z(n, 0);

    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {

        if (i <= R) {
            Z[i] = min(R - i + 1, Z[i - L]);
        }

        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }

        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }

    return Z;
}
