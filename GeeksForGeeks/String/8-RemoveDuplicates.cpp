// Remove Duplicates

// create a char array as count[256] ={0}, input string and store string length in len.
// for( i=0 to len): if count[character] is zero increase count and print that character.

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
    cin>>T;
    cin.ignore();
	while(T--){
	    string str1;
		char count[256] ={0};
        getline(cin,str1);
        int len = str1.length();
		for(int i=0;i<len;i++){
            if(count[str1[i]]++ == 0){
                cout<<str1[i];
            }
        }
        cout<<endl;
	}
	return 0;
}