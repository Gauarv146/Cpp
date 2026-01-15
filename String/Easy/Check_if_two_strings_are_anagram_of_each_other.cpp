//Optimal
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    // Step 1: Length check
    if (s.length() != t.length())
        return false;

    // Step 2: Frequency array for 26 lowercase letters
    int freq[26] = {0};

    // Step 3: Count characters in s
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Step 4: Subtract characters using t
    for (char c : t) {
        freq[c - 'a']--;
    }

    // Step 5: Verify all frequencies are zero
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }

    return true;
}

int main() {
    string s = "listen";
    string t = "silent";

    if (isAnagram(s, t))
        cout << "Anagram\n";
    else
        cout << "Not Anagram\n";

    return 0;
}
