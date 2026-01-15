//Optimal
#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.length();
    int count = 0;

    int freq[3] = {0, 0, 0};
    int left = 0;

    for (int right = 0; right < n; right++) {

        // Include current character in window
        freq[s[right] - 'a']++;

        // While window contains all three characters
        while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {

            // All substrings starting at left and ending from right to n-1 are valid
            count += (n - right);

            // Shrink window from left
            freq[s[left] - 'a']--;
            left++;
        }
    }
    return count;
}
