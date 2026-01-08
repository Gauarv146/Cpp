
// Manually input

// #include<iostream>
// using namespace std
// ;
// void printsquare(int size =4) {
//     for(int i =0; i<size;i++) {
//         for(int j=0;j<size;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

// int main() {
//     printsquare();
//     return 0;
// }

// User input 

#include<iostream>
using namespace std;

void printsquare(int size) {
    for(int i =0; i<size;i++) {
        for(int j=0;j<size;j++){
            cout<<"* ";  
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter the size of square: ";
    cin>>n;

    printsquare(n);
    return 0;
}