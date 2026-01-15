//Optimal
#include <iostream>
#include <vector>
using namespace std;

// Builds LPS (Longest Prefix Suffix) array
vector<int> buildLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);

    int len = 0;   // length of previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP search
bool kmpSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = buildLPS(pattern);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            return true; // match found
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return false;
}

bool isRotation(string s, string goal) {

    // Step 1: Length check
    if (s.length() != goal.length())
        return false;

    // Step 2: Concatenate string
    string doubled = s + s;

    // Step 3: KMP substring check
    return kmpSearch(doubled, goal);
}

int main() {
    string s = "abcde";
    string goal = "cdeab";

    cout << isRotation(s, goal);
    return 0;
}
