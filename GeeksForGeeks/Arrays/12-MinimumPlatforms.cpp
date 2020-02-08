// Minimum Platforms
// Create a multimap and store all arrival & departure times in it.
// Traverse map and if second value of map is 'a' then platform required will increment by 1, otherwise decrement by 1.
// keep update the maximum platform needed after each inc/dec operations.
#include <iostream>
#include <map> 
#include <iterator>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[N],dep[N],count=0,max=0;
		multimap <int, char> mp;
		multimap <int, char> :: iterator itr;

	    for(long int i=0;i<N;i++){
	        cin>>arr[i];
			mp.insert(pair <int, char> (arr[i], 'a'));
		}
		

		for(long int i=0;i<N;i++){
	        cin>>dep[i];
			mp.insert(pair <int, char> (dep[i], 'd'));
		}

		for (itr = mp.begin(); itr != mp.end(); ++itr) 
		{ 
			if(count > max)
				max = count;
			if(itr->second == 'a')
				count++;
			else if(itr->second == 'd')
				count--;
		}
		cout<<max<<endl;

	}
	return 0;
}