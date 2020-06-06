// Zero Sum Subarrays

// Create an unordered_map mp and traverse every element of array A.
// for each traversal make sum = sum + A[i] 
//     if(sum is present in map) then 
//         if(sum is 0) increment repeat and make count += repeat, update the map entry and make start= mp[sum].first and stop = i.
//         else make count += repeat, increment repeat, update map entry and make start= mp[sum].first+1 and stop = i.
//     else if(sum == 0) then increment count.
//         insert the pair (sum, make_pair(i,1)) into map.
// print count.

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,count=0,sum=0,start=0,stop=0;
        unordered_map<int, pair<int, int> > mp;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];

        for(int i=0;i<N;i++){
            sum += A[i];
            if(mp.find(sum) != mp.end()){
                if(sum == 0){
                    int repeat = mp[sum].second;
                    int index = mp[sum].first;
                    repeat++;
                    count += repeat;
                    mp[sum] = make_pair(index, repeat);
                    start = mp[sum].first;
                    stop = i;
                }
                else{
                    int repeat = mp[sum].second;
                    int index = mp[sum].first;
                    count += repeat;
                    repeat++;
                    mp[sum] = make_pair(index, repeat);
                    start = mp[sum].first+1;
                    stop = i;
                }
            }
            else{
                if(sum == 0)
                    count++;
                mp.insert(make_pair(sum, make_pair(i,1)));
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}

