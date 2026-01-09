//Optimal
#include <bits/stdc++.h>
using namespace std;

// Greedy feasibility check
bool canPaint(const vector<int>& boards, int k, int maxTime) {
    int painters = 1;
    int painted = 0;

    for (int len : boards) {
        if (painted + len <= maxTime) {
            painted += len;
        } else {
            painters++;
            painted = len;
            if (painters > k) return false;
        }
    }
    return true;
}

int paintersPartitionOptimal(const vector<int>& boards, int k) {
    // Edge case: more painters than boards
    if (k >= boards.size()) {
        return *max_element(boards.begin(), boards.end());
    }

    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (canPaint(boards, k, mid)) {
            high = mid;        // try smaller maximum time
        } else {
            low = mid + 1;     // need more time
        }
    }
    return low;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    cout << paintersPartitionOptimal(boards, k);
    return 0;
}
