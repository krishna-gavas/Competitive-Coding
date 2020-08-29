// Max length chain

#include <iostream>
#include <algorithm>
using namespace std;

struct val{
	int first;
	int second;
};

bool compareVal(val i1, val i2) 
{ 
    return (i1.first > i2.first); 
}

int maxChainLen(struct val P[],int N)
{
    int count=1,ele;
    sort(P,P+N,compareVal);
    ele = P[0].first;
    for(int i=1;i<N;i++){
        if(P[i].second < ele){
            ele = P[i].first;
            count++;
        }
    }
    return count;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
        cin>>N;
        val P[N];
        for(int i=0;i<N;i++)
            cin>>P[i].first>>P[i].second;
        cout<<maxChainLen(P,N)<<"\n";
	}
	return 0;
}