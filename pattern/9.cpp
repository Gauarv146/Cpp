#include<iostream>
using namespace std; 

void prints7(int n) {
    for(int i=0;i<n;i++) {
        //space
        for(int j=0;j<n-i-1;j++) {
            cout<<" ";
        }
        //star
        for(int j=0;j<=2*i+1;j++) {
            cout<<"* ";
        }             
        
        //space
        for(int j=0;j<n-i-1;j++) {
            cout<<" ";
        }   

        cout<<endl;         
    }
}

void prints8(int n) {
    
    for(int i=0;i<n;i++) {
        //space
        for(int j=0;j<1;j++) {
            cout<<" ";
        }
        //star
        for(int j=0;j<2*n-(2*i+1);j++) {
            cout<<"* ";
        }             
        
        //space
        for(int j=0;j<1;j++) {
            cout<<" ";
        }   

        cout<<endl;         
    }
}


int main() {
    int n;
    cout<<"Enter the size of trangle: ";
    cin>>n;
    prints7(n);
    prints8(n);
    return 0;
}
