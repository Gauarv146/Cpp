#include<iostream>
using namespace std;

bool f(int i, string &s) {
    if(i>= s.size()/2) return true;
    if(s[i] != s[s.size()-i-1]) return false;
    return f(i+1, s);
}
int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    if(f(0, s)) {
        cout<<"The string is a palindrome."<<endl;
    } else {
        cout<<"The string is not a palindrome."<<endl;
    }
    return 0;
}