// Sorting Elements of an Array by Frequency

// create a map named count to store count of elements of array A1 and create A2 of size N to store sorted elements.
// create a multimap named mp and copy key of count to value of mp and value of count as key of mp.
// traverse map mp and store each element in A2 for its count.

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin>>T;
    while(T--){
        int N,k=0;
        cin>>N;
        int A1[N], A2[N];
        map<int, int> count;
        multimap<int, int, greater <int> > mp;
        map<int, int> :: iterator it;
        multimap<int, int> :: iterator it1;
        for(int i=0;i<N;i++){
            cin>>A1[i];
            if(count.find(A1[i]) != count.end())
                count[A1[i]] = count[A1[i]] + 1;
            else
                count.insert(make_pair(A1[i], 1));
        }

        for(it = count.begin();it != count.end(); it++){
            mp.insert(make_pair(it->second,it->first));
        }
        for(it1 = mp.begin();it1 != mp.end(); it1++){
            for(int i=0;i<it1->first;i++)
                A2[k++] = it1->second;
        }

        for(int i=0;i<N;i++)
            cout<<A2[i]<<" ";
        cout<<endl;
    }
    return 0;
}
