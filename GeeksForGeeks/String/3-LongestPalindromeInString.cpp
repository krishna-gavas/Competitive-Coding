// Longest Palindrome in a String( Abort signal from abort(3) (SIGABRT) )

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str1;
        cin>>str1;
        int len = str1.length(),start,begin1,begin2;
        int l,r,count,max1=0,max2=0;

        // //-------------even length palindrome----------------
		for(int i=1;i<len;i++){
            l = i-1;
            r = i+1;
            count = 1;
            while((str1[l]==str1[r]) && (l>=0) && (r<=len)){
                count = count + 2;
                start = l;
                l--;
                r++;
            }
            if(count > max1){
                max1 = count;
                begin1 = start;
            }
        }          

        // -------------Odd length palindrome----------------
        int j=1;
        for(int i=0;i<len-1;i++){         
            count = 0;
            if(str1[i]==str1[j]){
                l = i-1;
                r = j+1;
                count = count + 2;
                start = l;
                while((str1[l]==str1[r]) && (l>=0) && (r<=len)){
                    count = count + 2;
                    start = l;
                    l--;
                    r++;
                }
                if(count > max2){
                    max2 = count;
                    begin2 = start;
                }
            }
            j++;
        }

        if(max1 > max2)
            cout<<str1.substr(begin1,max1)<<endl;
        else
            cout<<str1.substr(begin2,max2)<<endl;  
	}
	return 0;
}