// First non-repeating character in a stream

// Question:
// Given an input stream of N characters consisting only of lower case alphabets. The task is to find the first non 
// repeating character, each time a character is inserted to the stream. If no non repeating element is found print -1.

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test 
// case contains an integer N denoting the size of the stream. Then in the next line are x characters which are 
// inserted to the stream.

// Output:
// For each test case in a new line print the first non repeating elements separated by spaces present in the stream 
// at every instinct when a character is added to the stream, if no such element is present print -1

// Example:
// Input:
// 2
// 4
// a a b c
// 3
// a a c

// Output:
// a -1 b b
// a -1 c

// Solution:
// Create a vector q which acts like a queue but we can delete any in between elements from it
// also create an array count[26] to store the count of characters and initialize it to 0
// for(i=0 to n): input in[i]
//     if(count[in[i]] is 0) then push in[i] to q and increment count[in[i]]
//     else check whether in[i] is present in q if yes then delete it from q 
//     if(q is not empty) then print front of q 
//     else print -1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    char in[n];
	    vector<char> q;
	    vector<char>::iterator it; 
	    int count[26] = {0};
        for(int i=0;i<n;i++){
            cin>>in[i];
            if(count[in[i] - 'a'] == 0){
                q.push_back(in[i]);
                count[in[i] - 'a']++;
            }
            else{
                it = find(q.begin(), q.end(), in[i]);
                if(it != q.end()){
                    q.erase(it);
                }
            }
            if(!q.empty()){
                it = q.begin();
                cout<<*it<<" ";
            }
            else 
                cout<<-1<<" ";
            
        }
        cout<<"\n";
	}
	return 0;
}