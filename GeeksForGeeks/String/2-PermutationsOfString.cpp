// Permutations of a given string
// recursively swap elements 

// Question:
// Given a string S. The task is to print all permutations of a given string.

// Input:
// The first line of input contains an integer T, denoting the number of test cases. Each test case contains a 
// single string S in capital letter.

// Output:
// For each test case, print all permutations of a given string S with single space and all permutations should 
// be in lexicographically increasing order.

// Example:
// Input:
// 2
// ABC
// ABSG

// Output:
// ABC ACB BAC BCA CAB CBA 
// ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA 
// SGAB SGBA

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> vec;

void PermuteString(string str,int i,int len){
    if(i>=len)
        return;
    for(int j=i;j<len;j++){
        string str1 = str;
        swap(str1[i],str1[j]);
        if(i == (len-1))
            vec.push_back(str1);

        PermuteString(str1,i+1,len);
    }       
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str1;
        
        vec.clear(); 
        cin>>str1;
        int len = str1.length();

        PermuteString(str1,0,len);
    
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++)
            cout<<vec[i]<<" ";  

		cout<<endl;
	}
	return 0;
}