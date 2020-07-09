// Largest number possible

// if(S > N*9 or (S is 0 and N > 1)) then print -1.
// else 
//     while(S >= 0 && N > 0): if(S/10 > 0) then print 9 and subtract 9 from S.
//         else print (S % 10) and subtract (S % 10) from S.
//         decrement N;

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,S;
        cin>>N>>S;
        if(S > N*9 || (S == 0 && N > 1))
            cout<<-1;
        else{
            while(S >= 0 && N > 0){
                if(S/10 > 0){
                    cout<<9;
                    S = S - 9;
                }
                else{
                    cout<<S % 10;
                    S = S - (S % 10);
                }
                N--;
            }
        }
        cout<<endl;
    }
    return 0;
}
