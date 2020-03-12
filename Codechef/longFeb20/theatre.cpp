// The Theatre Problem

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int T,totalsum=0;
	cin>>T;
	while(T--){
	    int N,max=0,max1=-99999999,max2=0,cash=100;
        cin>>N;
        char m[N];
        int t[N];
        int mat[4][4] = {0};
        int a[4] = {0,1,2,3},b[4],c[13];
        c[12] = 0;c[3] = 1;c[6] = 2;c[9] = 3;
        
        for(int i=0;i<N;i++){
            cin>>m[i]>>t[i];
            switch (m[i])
            {
            case 'A':   (mat[0][c[t[i]]])++;
                        break;

            case 'B':   (mat[1][c[t[i]]])++;
                        break;

            case 'C':   (mat[2][c[t[i]]])++;
                        break;

            case 'D':   (mat[3][c[t[i]]])++;
                        break;
            
            default:    break;
            }
        }

        do { 
            int sum = 0,price = 100;
            b[0] = mat[0][a[0]];
            b[1] = mat[1][a[1]];
            b[2] = mat[2][a[2]];
            b[3] = mat[3][a[3]];
            sort(b, b + 4);
            for(int i=3;i>=0;i--){
                if(b[i] != 0)
                    sum = sum + (b[i]*price);
                else
                    sum = sum - 100;
                price = price - 25;
            }
            if(sum <= 0){
                if(sum >= max1)
                    max1 = sum;

            }else{
                if(sum > max2)
                    max2 = sum;
            }

        } while(next_permutation(a, a + 4));

        if(max2 > 0)
            max = max2;
        else
            max = max1;           

        cout<<max<<endl;
        totalsum = totalsum + max;
	}
    cout<<totalsum<<endl;
	return 0;
}