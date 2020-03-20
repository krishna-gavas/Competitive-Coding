// Pintu and Fruits (Partially Executed)

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false); 
//     cin.tie(NULL);
// 	int T;
// 	cin>>T;
// 	while(T--){
// 	    int N,M,min = 1000;
//         cin>>N>>M;
//         int F[N],P[N];
//         map<int, int> mp;
//         map<int, int>::iterator itr;
//         for(int i=0;i<N;i++)
//             cin>>F[i];

//         for(int i=0;i<N;i++){
//             cin>>P[i];
//             if (mp.find(F[i]) != mp.end())
//                 mp[F[i]] = mp[F[i]] + P[i];
//             else
//                 mp.insert(pair<int, int>(F[i], P[i]));
//         }

//         for (itr = mp.begin(); itr != mp.end(); ++itr) { 
//             if(itr->second  < min)
//                 min = itr->second;
//         }
//         cout<<min<<"\n";
        
// 	}
// 	return 0;
// }

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,M,pos = 0;
        scanf("%d%d",&N,&M);
        int F[N],P[N],cost[M+1];
        for(int i=0;i<N;i++){
            scanf("%d",&F[i]);
            if(i<=M)
                cost[i] = 0;
        }

        for(int i=0;i<N;i++){
            scanf("%d",&P[i]);
            if(cost[F[i]] != 0)
                cost[F[i]] = cost[F[i]] + P[i];
            else {
                cost[F[i]] = P[i];
                pos++;
            }
        }

        sort(cost, cost+M+1);
        cout<<cost[M+1-pos]<<endl;
        
	}
	return 0;
}

