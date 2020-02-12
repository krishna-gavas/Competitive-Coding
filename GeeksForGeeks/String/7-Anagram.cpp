// Anagram(not submitted)

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str1,str2;
		map<char, int> map1;
		map<char, int> map2;
        cin>>str1>>str2;
        int len1 = str1.length(),len2 = str2.length();

		for(int i=0;i<len1;i++){
			// remove from map2
			if(map2.count(str1[i]) == 1){
				if(map2[str1[i]] > 1)
					map2[str1[i]]--;
				else
					map2.erase(str1[i]);
			}
			else{
				if(map1.count(str1[i]) == 1)
					map1[str1[i]]++;
				else 
					map1.insert(pair<char, int>(str1[i], 1));
			}

			// remove from map1
			if(map1.count(str2[i]) == 1){
				if(map1[str2[i]] > 1)
					map1[str2[i]]--;
				else
					map1.erase(str2[i]);
			}
			else{
				if(map2.count(str2[i]) == 1)
					map2[str2[i]]++;
				else 
					map2.insert(pair<char, int>(str2[i], 1));
			}
		}

		if(map1.empty() && map2.empty())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
           
	}
	return 0;
}