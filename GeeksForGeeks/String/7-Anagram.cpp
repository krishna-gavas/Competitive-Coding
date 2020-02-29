// Anagram(not submitted)
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string s1,s2;
		char* ch1,ch2;
		int arr[26] = {0};
		int i=0,flag = 0;
        while(true){
			cin>>ch1[i];
			if(ch1[i] == " ")
				break;
			i++;
		}
		i=0;
        while(true){
			cin>>ch2[i];
			if(ch2[i] == " ")
				break;
			i++;
		}

		sort(ch1,ch1+len1);
		sort(ch2,ch2+len1);
		
		s1 = ch1;
		s2 = ch2;

		if(s1 == s2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
           
	}
	return 0;
}