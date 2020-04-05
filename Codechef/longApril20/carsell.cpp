// Sell All the Cars 

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,max;
	    long int profit = 0;
        cin>>N;
        int P[N];
        vector<int> vec;
        vector<int>::iterator pos;
        for(int i=0;i<N;i++){
            cin>>P[i];
            vec.push_back(P[i]);
        }
        for(int i=0;i<N;i++){
            max = *max_element(vec.begin(), vec.end());
            pos = find(vec.begin(), vec.end(), max);
            vec.erase(pos);
            if(max-i > 0)
                profit = profit + (max - i);
        }
        cout<<profit%1000000007<<"\n";
	}
	return 0;
}