/*Write a program that determines the maximum and the minimum of three
numbers. */

#include<iostream>
using namespace std;

int Max(int n1, int n2, int n3) {
    int max = n1;
    if (n2 > max) {
        max = n2;
    }
    if (n3 > max) {
        max = n3;
    }
    return max;
}

int Min(int n1, int n2, int n3) {
    int min = n1;
    if (n2 < min) {
        min = n2;
    }
    if (n3 < min) {
        min = n3;
    }
    return min;
}

int main(){
    int n1, n2, n3;
    cout<<"Enter the three numbers: ";
    cin>>n1>>n2>>n3;

    int max= Max(n1,n2,n3); 
    int min= Min(n1,n2,n3);

    cout<<"MAXIMUM = "<< max << "and MINIMUM = "<< min;
    return 0;
}



// void max(int n1, int n2, int n3){
//    if (n1 > n2 && n1 > n3){
//         cout<<n1<<" is the maximum.";
//         }
//     else if (n2 > n1 && n2 > n3){
//         cout<<n2<<" is the maximum.";
//     }
//     else
//     cout<<n3<<" is the maximum."; 
// }

// void min(int n1, int n2, int n3){
//      if (n1 < n2 && n1 < n3){
//         cout<<n1<<" is the minimum.";
//         }
//     else if (n2 < n1 && n2 < n3){
//         cout<<n2<<" is the minimum.";
//     }
//     else
//     cout<<n3<<" is the minimum." ;

// }

// int main(){
//     int n1, n2, n3;
//     cout<<"Enter the three numbers: ";
//     cin>>n1>>n2>>n3;
//     max(n1,n2,n3); 
//     cout<<"\n";
//     min(n1,n2,n3);
//     return 0;
// }
