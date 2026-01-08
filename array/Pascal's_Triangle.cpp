//optimal

#include <iostream>
using namespace std;

int main() {
    int n = 5;          // row index (0-based)
    long long ans = 1;  // C(n, 0)

    cout << ans << " ";

    for (int r = 1; r <= n; r++) {
        ans = ans * (n - r + 1) / r;
        cout << ans << " ";
    }

    return 0;
}
