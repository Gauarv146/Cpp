//Optimal
#include <bits/stdc++.h>
using namespace std;

string shortestPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());

    string combined = s + "#" + rev;
    int n = combined.length();

    vector<int> lps(n, 0);

    // Build LPS array
    for (int i = 1; i < n; i++) {
        int len = lps[i - 1];

        while (len > 0 && combined[i] != combined[len]) {
            len = lps[len - 1];
        }

        if (combined[i] == combined[len]) {
            len++;
        }

        lps[i] = len;
    }

    int longestPrefix = lps[n - 1];

    string suffix = s.substr(longestPrefix);
    reverse(suffix.begin(), suffix.end());

    return suffix + s;
}
