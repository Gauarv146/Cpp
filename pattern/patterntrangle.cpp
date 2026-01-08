
//manually input
// #include<iostream>
// using namespace std;

// void trangle(int n=5)
// {

//     for(int i=0;i<n;i++) {
//         for(int j=0;j<=i;j++) {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

// int main() {
//     trangle();
//     return 0;
// }

//user input
#include<iostream>
using namespace std;        

void trangle(int n) 
{
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter the size of trangle: ";
    cin>>n;
    trangle(n);
    return 0;
}