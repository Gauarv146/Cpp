//Optimal
#include <bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int>& pages, int M, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (pagesSum + pages[i] <= maxPages) {
            pagesSum += pages[i];
        } else {
            students++;
            pagesSum = pages[i];

            if (students > M) return false;
        }
    }
    return true;
}

int bookAllocationOptimal(vector<int>& pages, int M) {
    int N = pages.size();
    if (M > N) return -1;

    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);

    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(pages, M, mid)) {
            answer = mid;        // store potential answer
            high = mid - 1;      // try to minimize
        } else {
            low = mid + 1;       // increase limit
        }
    }
    return answer;
}
