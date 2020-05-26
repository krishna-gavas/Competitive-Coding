// Combination Sum - Part 2

// Create a vector current to store a combination and create another 2d vector result to store all combinationSum.
// Sort the array, initialize flag = 0 and call combinationSum(A,N,S,0,current,result,&flag).
// combinationSum(A,N,target,index,current,result,*flag): if(target == 0) then make flag=1 and push current to result. 
//     if(target < 0) then return
//     for(i=index to n):
//         if(i== index or A[i] != A[i-1]) then push A[i] to current, call combinationSum(A,n,target-A[i],i+1,current,result,flag) and pop_back current.
// if(flag == 0)
//     print "Empty".

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void combinationSum(int A[], int n, int target,int index, vector<int> current, vector< vector<int> > result,int *flag){
    if(target == 0){
        *flag = 1;
        result.push_back(current);
        cout<<"(";
        for(int i=0;i<current.size();i++){
            if(i==0)
                cout<<current[i];
            else
                cout<<" "<<current[i];
        }
        cout<<")";
        return;
    }
    if(target < 0)
        return ;
    for(int i=index; i < n; i++){
        if(i == index || A[i] != A[i-1]){
            current.push_back(A[i]);
            combinationSum(A,n,target-A[i],i+1,current,result,flag);
            current.pop_back();
        }
    }
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,S;
        cin>>N;
        int A[N];
        vector< vector<int> > result;
        vector<int> current;
        for(int i=0;i<N;i++)
            cin>>A[i];
        cin>>S;
        sort(A,A+N);
        int flag = 0;
        combinationSum(A,N,S,0,current,result,&flag);
        if(flag == 0)
            cout<<"Empty";
        cout<<endl;
        // for(int i=0;i<result.size();i++){
        //     for(int j=0;j<result[i].size();j++){
        //         cout<<result[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    return 0;
}
