//Optimal
#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {

    // Start scanning from the end of the string
    for (int i = num.size() - 1; i >= 0; i--) {

        // Convert character to integer digit
        if ((num[i] - '0') % 2 == 1) {

            // Return prefix ending at the first odd digit found
            return num.substr(0, i + 1);
        }
    }

    // If no odd digit exists, no valid odd number can be formed
    return "";
}
