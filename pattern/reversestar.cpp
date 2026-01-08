#include<iostream>
using namespace std;    

void reverseStar(int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main() {
    int s;
    cout<<"Enter the Number: ";
    cin>>s;
    reverseStar(s);
    return 0;
}