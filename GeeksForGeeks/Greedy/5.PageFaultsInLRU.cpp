// Page Faults in LRU

// Question:
// In operating systems that use paging for memory management, page replacement algorithm are needed to decide 
// which page needs to be replaced when the new page comes in. Whenever a new page is referred and is not present 
// in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed 
// page. Given a sequence of pages and memory capacity, your task is to find the number of page faults using Least 
// Recently Used (LRU) Algorithm.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Each test case contains n 
// number of pages and next line contains space seaprated sequence of pages. The following line consist of the 
// capacity of the memory. 
// Note: Pages are referred in the order left to right from the array (i.e index 0 page is referred first then 
// index 1 and so on). Memory is empty at the start.

// Output:
// Output the number of page faults.

// Example:
// Input:
// 2
// 9
// 5 0 1 3 2 4 1 0 5
// 4
// 8
// 3 1 0 2 5 4 1 2
// 4

// Output:
// 8
// 7

// Solution:
// Initialize pf=0 and create a vector lru to store the pages.
// for(i=0 to N): it = find A[i] in lru.
//     if(A[i] is present in lru) then delete A[i] from lru and push A[i] to lru.
//     else if(lru.size() == cap) then erase lru.begin() 
//         push A[i] to lru and increment pf. 
// print pf.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,cap,pf=0;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cin>>cap;
        
        vector<int> lru;
        vector<int> :: iterator it;
        for(int i=0;i<N;i++){
            it = find(lru.begin(), lru.end(), A[i]);
            if( it != lru.end()){
                lru.erase(it);
                lru.push_back(A[i]);
            }
            else{
                if(lru.size() == cap)
                    lru.erase(lru.begin());
                lru.push_back(A[i]);
                pf++;
            }
        }
        cout<<pf<<endl;
    }
    return 0;
}

