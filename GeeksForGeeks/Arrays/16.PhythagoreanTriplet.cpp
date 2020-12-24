// Pythagorean Triplet(using meet in the middle algorithm)

#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution{
public:
	bool checkTriplet(int A[], int N) {
	    sort(A,A+N);
	    int L,R,num,sum;
	    for(int i=N-1; i>1; i--){
	        L = 0;
	        R = i-1;
	        num = A[i] * A[i];
	        while(L < R){
	            sum = (A[L]*A[L]) + (A[R]*A[R]);
	            if(sum == num)
	                return true;
	            else if(sum > num)
	                R--;
	            else 
	                L++;
	        }
	    }
	    return false;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}