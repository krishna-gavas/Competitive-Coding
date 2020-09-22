#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int gap = n-1;
    int fill = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<gap;j++)
            cout<<"   ";
        for(int j=0;j<fill;j++)
            cout<<" * ";
        for(int j=0;j<gap;j++)
            cout<<" ";
        cout<<endl;
        gap--;
        fill = fill + 2;
    }

    return 0;
}