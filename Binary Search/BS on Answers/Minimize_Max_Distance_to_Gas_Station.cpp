//Optimal
#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& stations, int K, double dist) {
    int needed = 0;

    for (int i = 0; i < stations.size() - 1; i++) {
        double gap = stations[i + 1] - stations[i];
        int cnt = gap / dist;

        if (gap == dist * cnt) cnt--;
        needed += cnt;
    }

    return needed <= K;
}

double minimizeMaxDistance(vector<int>& stations, int K) {
    int n = stations.size();

    double low = 0;
    double high = 0;

    for (int i = 0; i < n - 1; i++) {
        high = max(high, (double)(stations[i + 1] - stations[i]));
    }

    while (high - low > 1e-6) {
        double mid = (low + high) / 2.0;

        if (canPlace(stations, K, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}
