#include <iostream>
using namespace std;

void printConcentricSquare(int n) {
    int size = 2 * n - 1;  // total rows and columns

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int top = i;
            int left = j;
            int right = size - 1 - j;
            int bottom = size - 1 - i;
            int minDist = min(min(top, bottom), min(left, right));

            cout << n - minDist;  // value decreases toward center
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    printConcentricSquare(n);
    return 0;
}
