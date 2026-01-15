//Optimal
#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";

    // Step 1: Transform the string
    string t = "^";
    for (char c : s) {
        t += "#";
        t += c;
    }
    t += "#$";

    int n = t.length();
    vector<int> P(n, 0);

    int center = 0, right = 0;

    // Step 2: Main loop
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            P[i] = min(right - i, P[mirror]);

        // Expand around center i
        while (t[i + P[i] + 1] == t[i - P[i] - 1])
            P[i]++;

        // Update center and right boundary
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }

    // Step 3: Find maximum palindrome
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Step 4: Extract answer
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s = "babad";
    cout << longestPalindrome(s);
    return 0;
}
