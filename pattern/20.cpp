#include <iostream>
using namespace std;

void printPattern(int n) {
    // Upper half
    for (int i = 1; i <= n; i++) {
        // Left stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // Spaces in the middle
        for (int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }

        // Right stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    // Lower half (mirror)
    for (int i = n - 1; i >= 1; i--) {
        // Left stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // Spaces in the middle
        for (int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }

        // Right stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }
}

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    printPattern(rows);
    return 0;
}
