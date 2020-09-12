#include<iostream>
using namespace std;

struct router{
    int ip;
    int subnet;
    char interface;
};

int main(){
    int testip;
    char interface;
    struct router r[10];
    r[0].ip = 11;
    r[0].subnet = 10;
    r[0].interface = 'a';
    r[1].ip = 22;
    r[1].subnet = 20;
    r[1].interface = 'b';
    r[2].ip = 33;
    r[2].subnet = 30;
    r[2].interface = 'c';
    cin>>testip;
    for(int i=0;i<3;i++){
        if(r[i].subnet & testip == r[i].subnet & r[i].ip ){
            interface = r[i].interface;
            return;
        }
    }
    cout<<interface<<endl;
}