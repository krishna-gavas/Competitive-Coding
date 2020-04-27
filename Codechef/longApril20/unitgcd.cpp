// Unit GCD

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int gcd(int a, int b){
	if (b == 0) 
        return a; 
    return gcd(b, a % b);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,count=1;
        cin>>N;
		map<int,vector<int> > mp;
		vector<int> v;
		vector<int> :: iterator it;
		v.push_back(1);
		mp[1] = v;
		for(int i=2;i<N/2;i++){
			vector<int> v1;
			v1.push_back(0);
			mp[i] = v1;
		}
        for(int i=2;i<=N;i++){
			for(int j=0;j<count;j++){
				vector<int> v2 = mp[j];
				int len = v2.size();
				int flag = 0;
				for(it = v2.begin();it != v2.end(); it++){
					if(gcd(i, *it) != 1){
						flag = 1;
						break;
					}
				}
				if(flag == 1 && j==count-1){
					cout<<i<<" "<<j<<"first"<<endl;
					vector<int> v3;
					v3.push_back(i);
					count++;
					mp[count] = v3;
					break;
				}
				else if(flag == 0){
					cout<<i<<" "<<j<<"second"<<endl;
					vector<int> v3;
					v3 = mp[j+1];
					v3.push_back(i);
					// mp[j].push_back(i);
					mp[j] = v3;
					break;
				}
			}
		}
		for(int i=1;i<=count;i++){
			vector<int> v3 = mp[i];
			int len = v3.size();
			for(int j=0;j<len;j++){
				cout<<v3[j]<<" ";
			}
			cout<<endl;
		}
		cout<<count<<endl;

	}
	return 0;
}