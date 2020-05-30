// Find all four sum numbers

// sort the array and fix the first 2 elements one by one( A[i] and A[j]) and find the other 2 elements.
// initialize 2 varialbles as indexes of first and last elements(l and r) in the remaining elements.
// to find the remaining 2 elements, move the index variables(l and r) toward each other.


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K, c=0;
        cin>>N>>K;
        int a[N];
        for(int i=0;i<N;i++) cin>>a[i];
        sort(a, a+N);
        map<string, int> m;
        string str="";
        for(int i=0;i<N-2;i++){
            for(int j=i+1;j<N-2;j++){
                int l=j+1, r=N-1;
                while(l<r){
                    if(a[i]+a[j]+a[l]+a[r]==K){
                        c++;
                        str = to_string(a[i])+to_string(a[j])+to_string(a[l])+to_string(a[r]);
	                    if(m[str]==0){
	                        cout<<a[i]<<" "<<a[j]<<" "<<a[l]<<" "<<a[r]<<" "<<"$";
	                        m[str]++;	                            
	                    }
                        l++;
                        r--;
                    }
                    else if(a[i]+a[j]+a[l]+a[r]>K) 
                        r--;
                    else 
                        l++;
                }
            }
        }
        if(c==0) cout<<"-1";
        cout<<endl;
    }
    return 0;
}

