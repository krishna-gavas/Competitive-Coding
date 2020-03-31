// Circular tour

#include <iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
    int totalp, totald, count, flag;
    for(int i=0;i<n;i++){
        totalp = 0;
        totald = 0;
        count = 0;
        int j = i;
        flag = 0;
        while(totalp >= totald && count<n){
            totalp += p[j].petrol;
            totald += p[j].distance;
            count++;
            j = (j+1)%n;
            flag = 1;
        }
        if(i == j && flag == 1 && totalp >= totald)
            return i;
    }
    return -1;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    petrolPump p[n];

	    for(int i=0;i<n;i++)
	        cin>>p[i].petrol>>p[i].distance;

        cout<<tour(p,n)<<"\n";
	}
	return 0;
}