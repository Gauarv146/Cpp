#include <iostream>
using namespace std;

int main() {
    int age;
    cin >> age;
    cout << "Enter Your age: ";
    if (age<18) {
        cout << "you are not eligible for job";
    }
    else if  (age<=57) {
        cout << "eligible for job";
        if(age >=55) {
            cout <<", but retirement soon";
        }
    }
    else {
        cout << "retirement time";
    }
    return 0;
}
