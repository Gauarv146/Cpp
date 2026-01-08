#include<iostream>
using namespace std;                

void reverseNumber(int n){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int s;
    cout<<"Enter the Number: ";
    cin>>s;
    reverseNumber(s);
    return 0;
}