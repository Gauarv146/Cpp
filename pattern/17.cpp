#include <iostream>
using namespace std;

void printAlphabetPattern(int n) {
    for (int i = 0; i < n; i++) {
        // Print ascending part: A to (A + i)
        for (int j = 0; j <= i; j++) {
            cout << char('A' + j);
        }

        // Print descending part: (A + i - 1) down to A
        for (int j = i - 1; j >= 0; j--) {
            cout << char('A' + j);
        }

        cout << endl;
    }
}

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    printAlphabetPattern(rows);
    return 0;
}
