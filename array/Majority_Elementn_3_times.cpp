//optimal

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();

    // Step 1: Find potential candidates
    int candidate1 = 0, candidate2 = 1; // initialized to different values
    int count1 = 0, count2 = 0;

    for (int x : nums) {
        if (x == candidate1) {
            count1++;
        }
        else if (x == candidate2) {
            count2++;
        }
        else if (count1 == 0) {
            candidate1 = x;
            count1 = 1;
        }
        else if (count2 == 0) {
            candidate2 = x;
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify actual frequencies
    count1 = 0;
    count2 = 0;

    for (int x : nums) {
        if (x == candidate1) count1++;
        else if (x == candidate2) count2++;
    }

    vector<int> result;
    if (count1 > n / 3) result.push_back(candidate1);
    if (count2 > n / 3) result.push_back(candidate2);

    return result;
}
