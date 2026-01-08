#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Your Number: ";
    if (!(cin >> n)) return 1; // input failed
    if (n < 0 || n > 100) {
        cout << "\nInvalid score. Enter a number between 0 and 100.";
        return 0;
    }

    if (n >= 80) {
        cout << "\nYou have passed with A grade.";
    } else if (n >= 60) {
        cout << "\nYou have passed with B grade.";
    } else if (n >= 50) {
        cout << "\nYou have passed with C grade.";
    } else if (n >= 45) {
        cout << "\nYou have passed with D grade.";
    } else if (n >= 25) {
        cout << "\nYou have passed with E grade.";
    } else {
        cout << "\nYou have failed.";
    }
    return 0;
}
