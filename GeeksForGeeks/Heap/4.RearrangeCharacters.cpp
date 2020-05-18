// Rearrange characters

// create a count array to store frequency count of characters( size is 125 because it only contains lower case characters).
// input string and store string length in len and initialize max as 0.
// for( i=0 to len): incremrnt count[str[i]]
//     if(count[str[i]] > max) then max = count[str[i]]
// if( (len is even and max <= len/2) or (len is odd and max <= (len+1)/2))

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
    cin>>T;
    while(T--){
        char count[125] = {0};
        string str;
        cin>>str;
        int len = str.length(),max=0;
        for(int i=0;i<len;i++){
            count[str[i]]++;
            if(count[str[i]] > max)
                max = count[str[i]];
        }
        if((len%2 == 0 && max <= len/2) || (len%2 == 1 && max <= (len+1)/2))
            cout<<1<<endl;
        else 
            cout<<0<<endl;
    }
}