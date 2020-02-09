// Permutations of a given string
// recursively swap elements 
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
        string arr[120];
        
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