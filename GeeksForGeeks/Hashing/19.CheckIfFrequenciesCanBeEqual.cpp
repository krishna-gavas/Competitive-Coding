// Check if frequencies can be equal

// Create an array ch[] to store count of all characters of the string, push these count values to a vector and sort it.
// initialize start and val with vec[0].
// for(i = 1 to vector size): 
//     if(vec[i] != start || vec[i] != val) make val = vec[i] for first time, increment flag and make a=vec[i], b=start.
//     if(flag == 2) the break out of the loop.
// if(first element is 1 and last and second element are equal ) then print 1.
// else if(flag == 2 || (flag == 1 && abs(a-b) >1)) then print 0.
// else print 1.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        int ch[150] = {0};
        cin>>str;
        int len = str.length(),min = INT_MAX, max = 0,flag=0;
        for(int i=0;i<len;i++)
            ch[str[i]]++;

        vector<int> vec;
        int a,b;
        for(int i=97;i<123;i++){
            if(ch[i] != 0){
                vec.push_back(ch[i]);
        }
        sort(vec.begin(), vec.end());
        int n = vec.size(),start = vec[0],val =vec[0];
        for(int i=1;i<n;i++){
            if(vec[i] != start || vec[i] != val){
                if(val == start)
                    val = vec[i];
                flag++;
                a = vec[i];
                b = start;
            }
            if(flag == 2)
                break;
        }
        if(vec[0] == 1 && vec[1] == vec[n-1])
            cout<<1<<endl;
        else if(flag == 2 || (flag == 1 && abs(a-b) >1))
            cout<<0<<endl;
        else 
            cout<<1<<endl;
    }
    return 0;
}

