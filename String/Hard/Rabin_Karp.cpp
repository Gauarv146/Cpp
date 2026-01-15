//Optimal
#include <bits/stdc++.h>
using namespace std;

class RabinKarp {
private:
    static const long long mod1 = 1000000007;
    static const long long mod2 = 1000000009;
    static const long long base = 31;

public:
    bool search(string text, string pattern) {
        int n = text.size();
        int m = pattern.size();
        if (m > n) return false;

        long long pHash1 = 0, pHash2 = 0;
        long long wHash1 = 0, wHash2 = 0;
        long long power1 = 1, power2 = 1;

        // base^(m-1)
        for (int i = 0; i < m - 1; i++) {
            power1 = (power1 * base) % mod1;
            power2 = (power2 * base) % mod2;
        }

        // Initial hashes
        for (int i = 0; i < m; i++) {
            int p = pattern[i] - 'a' + 1;
            int t = text[i] - 'a' + 1;

            pHash1 = (pHash1 * base + p) % mod1;
            pHash2 = (pHash2 * base + p) % mod2;

            wHash1 = (wHash1 * base + t) % mod1;
            wHash2 = (wHash2 * base + t) % mod2;
        }

        // Sliding window
        for (int i = 0; i <= n - m; i++) {
            if (pHash1 == wHash1 && pHash2 == wHash2) {
                // Character verification
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) return true;
            }

            // Roll hash
            if (i < n - m) {
                int out = text[i] - 'a' + 1;
                int in  = text[i + m] - 'a' + 1;

                wHash1 = (wHash1 - out * power1 % mod1 + mod1) % mod1;
                wHash1 = (wHash1 * base + in) % mod1;

                wHash2 = (wHash2 - out * power2 % mod2 + mod2) % mod2;
                wHash2 = (wHash2 * base + in) % mod2;
            }
        }

        return false;
    }
};

int main() {
    RabinKarp rk;
    cout << rk.search("ababcab", "abc");
    return 0;
}
