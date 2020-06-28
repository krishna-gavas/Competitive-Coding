// The Tom and Jerry Game!

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long long int TS,JS;
		int count = 0;
        cin>>TS;
		for(long long int i=1;i<TS;i++){
			JS = i;
			if((TS % 2 == 0 && JS % 2 == 1) || (TS % 2 == 1 && JS % 2 == 1))
				continue;
			else if(TS % 2 == 1 && JS % 2 == 0)
				count++;
			else if(TS % 2 == 1 && JS % 2 == 1){
				while((TS % 2 == 1 && JS % 2 == 1)){
					TS = TS / 2;
					JS = JS / 2;
				}
				if(TS % 2 == 1 && JS % 2 == 0)
					count++;
			}
		}
		cout<<count<<"\n";
	}
	return 0;
}