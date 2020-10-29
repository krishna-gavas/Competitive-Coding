// Special Keyboard

// Question:
// Imagine you have a special keyboard with the following keys: 

// Key 1:  Prints 'A' on screen
// Key 2: (Ctrl-A): Select screen
// Key 3: (Ctrl-C): Copy selection to buffer
// Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

// Find maximum numbers of A's that can be produced by pressing keys on the special keyboard N times. 

// Example 1:
// Input: N = 3
// Output: 3

// Example 2:
// Input: N = 7
// Output: 9

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function optimalKeys() which takes N 
// as input parameter and returns the maximum number of A's that can be on the screen after performing N operations.

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
