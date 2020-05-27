// Special Keyboard



#include <iostream>
#include <algorithm>
using namespace std;

int keyboard(int n){
    if(n < 5)
        return n;
    return max(4*keyboard(n-5), 3*keyboard(n-4));
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        cout<<keyboard(N)<<endl;
    }
    return 0;
}
