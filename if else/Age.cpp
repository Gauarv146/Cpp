#include<iostream>
using namespace std;

int main() {
    int age;
    cin >> age;
    cout <<"Enter Your Age: " << age;
    if(age>=18){
        cout<<" \n You are an adult!";
    } else{
        cout<<" \n You are not an  adult!";
    }
    return 0;
} 