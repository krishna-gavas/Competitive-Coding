// Largest subarray with 0 sum

// maxLen(A,n): Create a map to store sum value upto ith index. 
//     initialize sum,count and len to 0.
//     for(i=0 to n): sum = sum + A[i];
//         if(sum == 0) then len = i+1.
//         if(map contains sum) then  len = i - mp[sum] else insert (sum,i) to map.
//         if(len > count ) then count = len.
//     if(sum == 0) then return n.
//     finally return count.


#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int maxLen(int A[], int n) {
    map<int, int> mp;
    int sum=0,count=0,len=0;
    for(int i=0;i<n;i++){
        sum = sum + A[i];
        if(sum == 0){
            len = i+1;
        }
        if(mp.find(sum) != mp.end()){
            len = i - mp[sum];
        }
        else{
            mp.insert(make_pair(sum,i));
        }
        if(len > count)
            count = len;
    }
    if(sum == 0)
        return n;
    return count;
}


int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<maxLen(A,N)<<endl;
    }
    return 0;
}
