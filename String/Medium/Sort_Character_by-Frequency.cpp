//Optimal
#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    // Step 1: Count frequency
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Step 2: Create buckets
    vector<vector<char>> bucket(s.length() + 1);
    for (auto it : freq) {
        bucket[it.second].push_back(it.first);
    }

    // Step 3: Build result from high frequency to low
    string result = "";
    for (int i = s.length(); i > 0; i--) {
        for (char c : bucket[i]) {
            result.append(i, c);
        }
    }

    return result;
}
