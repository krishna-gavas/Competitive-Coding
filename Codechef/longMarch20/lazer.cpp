// Lasers Everywhere(Partially solved)

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,Q,x1,x2,y;
        scanf("%d%d",&N,&Q);
        int A[N],Px[N],Py[N],lstart[N-1][2],lend[N-1][2];
        int k = 0, l = 0;
        for(int i=0;i<N;i++){
            scanf("%d",&A[i]);
            Px[i] = i+1;
            Py[i] = A[i];
            if(i != 0 && i != N-1){
                lend[l][0] = Px[i];
                lend[l][1] = Py[i];
                l++;
                lstart[k][0] = Px[i];
                lstart[k][1] = Py[i];
                k++;
            }
            else if(i == 0){
                lstart[k][0] = Px[i];
                lstart[k][1] = Py[i];
                k++;
            }
            else if(i == N-1){
                lend[l][0] = Px[i];
                lend[l][1] = Py[i];
                l++;
            }           
        }


        for(int j=0;j<Q;j++){
            scanf("%d%d%d", &x1, &x2, &y);
            int count = 0;
            float height,h,l,slope,newpoint;
            for(int i=0;i<N-1;i++){
                if((y >= lstart[i][1] && y <= lend[i][1]) || (y <= lstart[i][1] && y >= lend[i][1])){
                    if(x2 != lstart[i][0] && x1 != lend[i][0]){
                        height = y - lstart[i][1];
                        h = lend[i][1] - lstart[i][1];
                        l = lend[i][0] - lstart[i][0];
                        slope = l/h;
                        newpoint = lstart[i][0] + slope*height;
                        if((x1 <= newpoint && x2 >= newpoint) || (x1 >= newpoint && x2 <= newpoint)){
                            count++;
                            // cout<<"height: "<<height<<"  h: "<<h<<"  l: "<<l<<"  slope: "<<slope<<"  newpoint: "<<newpoint<<endl;
                        }
                    }
                }
            }
            cout<<count<<endl;
        }
        
	}
	return 0;
}

