// Shortest path from 1 to N 

// Question:
// Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j 
// iff either j = i + 1 or j = 3i. The task is to find the minimum number of edges in a path in G from vertex 1 to 
// vertex n.

// Input:  
// The first line of input contains an integer T denoting the number of test cases. The description of T test cases 
// follows.
// Each test case contains a value of n. 

// Output:  
// Print the number of edges in the shortest path from 1 to n.

// Example:
// Input:
// 2
// 9
// 4

// Output:
// 2
// 2

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int edges=0;
	    while(N > 1){
	        if(N % 3 == 0)
    	        N = N/3;
    	    else
    	        N = N -1;
    	    edges++;
	    }
		cout<<edges<<"\n";
	}
	return 0;
}