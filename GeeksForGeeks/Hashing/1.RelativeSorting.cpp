// Relative Sorting

// create a map named count to store count of elements of array A1 and create A3 of size N to store sorted elements.
// while inputting elements of A2 check if A2[i] is present in count if present then copy that element its count times to A3.
// after completing input of A2 while(count is not empty) copy it->first to A3.

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin>>T;
    while(T--){
        int N,M,k=0;
        cin>>N>>M;
        int A1[N], A2[M], A3[N];
        map<int, int> count;
        map<int, int> :: iterator it;
        for(int i=0;i<N;i++){
            cin>>A1[i];
            if(count.find(A1[i]) != count.end())
                count[A1[i]] = count[A1[i]] + 1;
            else
                count.insert(make_pair(A1[i], 1));
        }
        for(int i=0;i<M;i++){
            cin>>A2[i];
            if(count.find(A2[i]) != count.end()){
                int len = count[A2[i]];
                for(int j=0;j<len;j++)
                    A3[k++] = A2[i];
                count.erase(A2[i]);
            }
        }
        for(it = count.begin();it != count.end(); it++){
            if(it->second > 1){
                for(int j=0;j<it->second;j++)
                    A3[k++] = it->first;
            }
            else
                A3[k++] = it->first;
        }

        for(int i=0;i<k;i++)
            cout<<A3[i]<<" ";
        cout<<endl;
    }
    return 0;
}
