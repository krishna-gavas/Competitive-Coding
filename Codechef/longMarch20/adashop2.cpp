// Ada Bishop 2 

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int T;
    int chess[9][9];
    for(int i=1;i<9;i++){
        for(int j=1;j<9;j++){
            if((i%2 == 0 && j%2 == 0) || ( i%2 == 1 && j%2 == 1))
                chess[i][j] = 1;
            else 
                chess[i][j] = 0;
        }
    }
	cin>>T;
	while(T--){
	    int r,c,temp,r1,c1,count=0,i=0,j=0;
        int R[64],C[64];
        cin>>r>>c;
        
        temp = (r+c)/2;
        R[i++] = temp; C[j++] = temp;
        R[i++] = 1; C[j++] = 1;
        R[i++] = 2; C[j++] = 2;
        count += 3;
        r = 2; c = 2;
        while(r != 8 || c != 8){
            r1 = r; c1 = c;
            while(chess[r1][c1] == 1 && r1<=8 && c1>=1){
                r1++;
                c1--;
            }
            r1--; c1++;
            R[i++] = r1; C[j++] = c1;

            r1 = r; c1 = c;
            while(chess[r1][c1] == 1 && r1>=1 && c1<=8){
                r1--;
                c1++;
            }
            r1++; c1--;
            R[i++] = r1; C[j++] = c1;
            R[i++] = r; C[j++] = c;
            r++; c++;
            R[i++] = r; C[j++] = c;
            count += 4;
        }

        cout<<count<<endl;
        for(int i=0;i<count;i++)
            cout<<R[i]<<" "<<C[i]<<endl;
        
	}
	return 0;
}
