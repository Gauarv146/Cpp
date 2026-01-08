#include <iostream>
using namespace std;

void printPattern() {
    char end = 'E';  // The last letter in the pattern

    for (int i = 1; i <= 5; i++) {
        if (i == 1) {
            cout << "E";
        } 
        else if (i == 2) {
            cout << "D" << "A";
        } 
        else {
            char start = end - i + 1;  // Start letter decreases each row
            for (char ch = start; ch <= end; ch++) {
                cout << ch;
            }
        }
        cout << endl;
    }
}

int main() {
    printPattern();
    return 0;
}
