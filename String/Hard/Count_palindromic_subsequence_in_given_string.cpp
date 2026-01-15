//Optimal
#include <bits/stdc++.h>
using namespace std;

int countDistinctPalindromicSubsequences(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> next(n), prev(n);

    unordered_map<char, int> last;

    // prev occurrence
    for (int i = 0; i < n; i++) {
        if (last.count(s[i])) prev[i] = last[s[i]];
        else prev[i] = -1;
        last[s[i]] = i;
    }

    last.clear();

    // next occurrence
    for (int i = n - 1; i >= 0; i--) {
        if (last.count(s[i])) next[i] = last[s[i]];
        else next[i] = n;
        last[s[i]] = i;
    }

    // base case
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // fill DP
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            if (s[i] != s[j]) {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            } else {
                int low = next[i];
                int high = prev[j];

                if (low > high) {
                    dp[i][j] = 2 * dp[i+1][j-1] + 2;
                } else if (low == high) {
                    dp[i][j] = 2 * dp[i+1][j-1] + 1;
                } else {
                    dp[i][j] = 2 * dp[i+1][j-1] - dp[low+1][high-1];
                }
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    string s = "aaa";
    cout << countDistinctPalindromicSubsequences(s);
    return 0;
}
