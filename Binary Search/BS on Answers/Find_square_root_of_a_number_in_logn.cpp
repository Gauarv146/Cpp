//Optimal
#include <iostream>
using namespace std;

int floorSqrt(int n) {
    // Base cases
    if (n == 0 || n == 1)
        return n;

    int low = 1;
    int high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Use long long to prevent overflow
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;           // Perfect square found
        }
        else if (square < n) {
            ans = mid;            // mid is a valid answer
            low = mid + 1;        // Try to find a bigger one
        }
        else {
            high = mid - 1;       // mid is too large
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << floorSqrt(n);
    return 0;
}
