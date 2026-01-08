//Optimal
#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithXorK(vector<int>& arr, int K) {
    unordered_map<int, int> freq;
    int xr = 0;
    int count = 0;

    freq[0] = 1;

    for (int i = 0; i < arr.size(); i++) {
        xr = xr ^ arr[i];
        int need = xr ^ K;

        if (freq.find(need) != freq.end()) {
            count += freq[need];
        }

        freq[xr]++;
    }

    return count;
}
