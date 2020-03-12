// XOR Engine(Partially executed)

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,Q,even,odd;
        scanf("%d%d",&N,&Q);
        int A[N],B[N],P;
        for(int i=0;i<N;i++)
            scanf("%d",&A[i]);

        for(int i=0;i<Q;i++){
            scanf("%d",&P);
            even = 0; 
            odd = 0;
            for(int i=0;i<N;i++){
                int n = A[i] ^ P;
                int count = 0;
                if(n==0){
                   even++;
                   continue;
                }
                while (n) { 
                    n &= (n - 1); // B[i] = n;
                    count++; 
                }
                if(count % 2 == 0)
                    even++;
            }
            printf("%d %d\n",even,N-even);
        }
        
	}
	return 0;
}

