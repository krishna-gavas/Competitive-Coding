// The Theatre Problem

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

multimap<int, string> invert(map<string, int> & mymap){
	multimap<int, string> multiMap;

	map<string, int> :: iterator it;
	for (it=mymap.begin(); it!=mymap.end(); it++){
		multiMap.insert(make_pair(it->second, it->first));
	}
	return multiMap;
}

int main() {
	int T,totalsum=0;
	cin>>T;
	while(T--){
	    int N,sum=0,cash=100;
        cin>>N;
        char m[N];
        int t[N];
        map<string,int> mymap;
        multimap<int, string> mp;
        multimap<int,string> :: reverse_iterator it;
        vector<string> movie;
        vector<string> time;
        vector<int> price;

        
        for(int i=0;i<N;i++){
            cin>>m[i]>>t[i];
            string str1(1,m[i]);
            string str2 = to_string(t[i]);
            string key;
            key.append(str1);
            key.append(str2);

            if(mymap.count(key) == 1)
                mymap[key] = mymap[key] + 1;
            else
                mymap.insert(pair<string, int>(key, 1));
        }
        mp = invert(mymap);

        for (it=mp.rbegin(); it!=mp.rend(); it++){
            string str,mov,tim;
            str = it->second;
            int len = str.length();
            mov = str.substr(0,1);
            tim = str.substr(1,len-1);
            if ((find(movie.begin(), movie.end(), mov) == movie.end()) && (find(time.begin(), time.end(), tim) == time.end())){
                movie.push_back(mov);
                time.push_back(tim);
                price.push_back(it->first);
            }
        }

        for(int i=0;i<price.size();i++){
            sum = sum + (cash * price[i]);
            cash = cash - 25;
        }
        sum = sum - (4 - price.size())*100;
        totalsum = totalsum + sum;
        cout<<sum<<endl;
	}
    cout<<totalsum<<endl;
	return 0;
}