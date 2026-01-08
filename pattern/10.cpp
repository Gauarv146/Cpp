
#include<iostream>
using namespace std; 

void printup(int n) {
    for(int i=0;i<n;i++) {
        //star
        for(int j=0;j<=i;j++) {
            cout<<"* ";
        }             

        cout<<endl;         
    }
}

void printdown(int n) {

    for(int i=0;i<n;i++) {
        for(int j=1;j<n-i;j++) {
            cout<<"* ";
        }             

        cout<<endl;         
    }
}
int main() {
    int n;
    cout<<"Enter the size of trangle: ";
    cin>>n;
    printup(n);
    printdown(n);
    return 0;
}
