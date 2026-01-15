//Optimal
#include <bits/stdc++.h>
using namespace std;

// Helper function to check if prefix of given length is common
bool isCommonPrefix(vector<string>& strs, int len) {
    string prefix = strs[0].substr(0, len);

    for (int i = 1; i < strs.size(); i++) {
        if (strs[i].substr(0, len) != prefix)
            return false;
    }
    return true;
}

string longestCommonPrefix(vector<string>& strs) {

    // Step 1: Edge case
    if (strs.size() == 0)
        return "";

    // Step 2: Find length of shortest string
    int minLen = INT_MAX;
    for (string s : strs)
        minLen = min(minLen, (int)s.length());

    // Step 3: Binary search boundaries
    int low = 0, high = minLen;

    // Step 4: Binary search on prefix length
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isCommonPrefix(strs, mid))
            low = mid + 1;   // try longer prefix
        else
            high = mid - 1;  // reduce prefix length
    }

    // Step 5: Extract final prefix
    return strs[0].substr(0, high);
}
