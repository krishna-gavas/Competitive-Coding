// Largest Number formed from an Array( Abort signal from abort(3) (SIGABRT) )

#include <iostream>
#include <string>
#include <map> 
#include <iterator>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin>>T;
    cin.ignore();
	while(T--){
        int N,k;
	    cin>>N;
	    int A[N],B[N];
        multimap <int, int> mp;
		multimap <int, int> :: iterator itr;

	    for(int i=0;i<N;i++){
	        cin>>A[i];
            int num=floor(log10(A[i]));
            int first = A[i]/pow(10,num);
            mp.insert(pair <int, int> (first, i));
        }

        k=0;
        for (itr = mp.begin(); itr != mp.end(); ++itr)
            B[k++] = A[itr->second];

        long long int x=B[0];
        for(int i=0;i<N-1;i++){
            long long int y=B[i+1];
            long long int xy = stoll(to_string(x) + to_string(y));
            long long int yx = stoll(to_string(y) + to_string(x));
            if(xy > yx)
                x = xy;
            else 
                x = yx;
        }

        cout<<x<<endl;
	}
	return 0;
}
// 123 456 654 321 987 776 346 764 234 998