//Optimal
#include <iostream>
#include <iomanip>
using namespace std;

// Checks if mid^N <= M without overflow
bool isPossible(double mid, int N, int M) {
    double result = 1.0;

    for (int i = 1; i <= N; i++) {
        result *= mid;
        if (result > M)
            return false;
    }
    return true;
}

double nthRoot(int N, int M) {
    double low = 0.0, high = M;
    double eps = 1e-6;

    while ((high - low) > eps) {
        double mid = (low + high) / 2.0;

        if (isPossible(mid, N, M))
            low = mid;
        else
            high = mid;
    }

    return low;
}

int main() {
    int N = 3;
    int M = 27;

    cout << fixed << setprecision(6) << nthRoot(N, M);
    return 0;
}
