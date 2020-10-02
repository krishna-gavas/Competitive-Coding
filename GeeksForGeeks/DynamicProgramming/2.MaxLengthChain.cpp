// Max length chain

// Question:
// You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. 
// A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have 
// to find the longest chain which can be formed from the given set of pairs. 

// Input:
// N = 5
// P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
// Output: 3

// Your Task:
// You don't need to read input or print anything. Your task is to Complete the function maxChainLen() which takes 
// a structure p[] denoting the pairs and n as the number of pairs and returns the length of the longest chain formed.

// Solution:
// maxChainLen:
//     Initialize count = 1 and sort P in descending order based on first value
//     make ele = P[0].first
//     for(i=1 to N)
//         if(P[i].second < ele) then ele = P[i].first and increment count
//     return count

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