#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    float x1,x2,y1,y2,pos;
        cin>>x1>>y1;
        cin>>x2>>y2;

        if(y1 == y2){
            pos = (x1 + x2)/2;
        }
        else if(y1 < y2){
            float lim = (x1 + x2)/2;
            for(float i=x1;i<lim;i=i+0.1){
                float a1,a2;
                a1 = y1/(sqrt((y1*y1) + ((i-x1)*(i-x1))));
                a2 = y2/(sqrt((y2*y2) + ((x2-i)*(x2-i))));
                if(abs(a1 - a2) < 0.01){
                    pos = i;
                    break;
                }
            }
        }
        else{
            float lim = (x1 + x2)/2;
            for(float i=x2;i>lim;i=i-0.1){
                float a1,a2;
                a1 = y1/(sqrt((y1*y1) + ((i-x1)*(i-x1))));
                a2 = y2/(sqrt((y2*y2) + ((x2-i)*(x2-i))));
                if(abs(a1 - a2) < 0.01){
                    pos = i;
                    break;
                }
            }
        }
        cout<<pos<<endl;
  
	}
	return 0;
}