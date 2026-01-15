//Optimal
#include <iostream>
using namespace std;

int minReversals(string s) {
    int n = s.length();

    // Step 1: Odd length cannot be balanced
    if (n % 2 != 0)
        return -1;

    int open = 0;   // count of unmatched '{'
    int close = 0;  // count of unmatched '}'

    // Step 2: Count unmatched brackets
    for (int i = 0; i < n; i++) {
        if (s[i] == '{') {
            open++;
        } else {
            if (open > 0)
                open--;   // cancels a valid "{}" pair
            else
                close++;  // unmatched '}'
        }
    }

    // Step 3: Minimum reversals
    return (open + 1) / 2 + (close + 1) / 2;
}
