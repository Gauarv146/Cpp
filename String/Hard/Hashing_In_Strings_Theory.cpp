//Optimal
#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;
static const long long P = 31;

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    // Step 1: Prefix hash array
    vector<long long> prefixHash(n + 1, 0);

    // Step 2: Power array
    vector<long long> power(n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        power[i] = (power[i - 1] * P) % MOD;
    }

    // Step 3: Build prefix hashes
    for (int i = 0; i < n; i++)
    {
        prefixHash[i + 1] =
            (prefixHash[i] + (s[i] - 'a' + 1) * power[i]) % MOD;
    }

    // Example: Compare substrings [l1, r1] and [l2, r2]
    int l1 = 0, r1 = 2;
    int l2 = 3, r2 = 5;

    long long hash1 =
        (prefixHash[r1 + 1] - prefixHash[l1] + MOD) % MOD;
    long long hash2 =
        (prefixHash[r2 + 1] - prefixHash[l2] + MOD) % MOD;

    // Normalize hashes
    if (hash1 * power[l2 - l1] % MOD == hash2)
        cout << "Substrings are equal\n";
    else
        cout << "Substrings are NOT equal\n";

    return 0;
}
