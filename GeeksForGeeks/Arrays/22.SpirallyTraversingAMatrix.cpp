// Spirally traversing a matrix

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int M,N,left,right,top,bottom,size1,size2=0;
	    cin>>M>>N;
	    int arr[M][N];
        size1 = M*N;
	    for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
	            cin>>arr[i][j];
       
        top = 0;
        bottom = M-1;
        left = 0;
        right = N-1;

        while(size2 < size1){
            for(int i=left;i<=right && size2 < size1;i++){
                cout<<arr[top][i]<<" ";
                size2++;
            }
            top++;

            for(int i=top;i<=bottom && size2 < size1;i++){
                cout<<arr[i][right]<<" ";
                size2++;
            }
            right--;

            for(int i=right;i>=left && size2 < size1;i--){
                cout<<arr[bottom][i]<<" ";
                size2++;
            }
            bottom--;

            for(int i=bottom;i>=top && size2 < size1;i--){
                cout<<arr[i][left]<<" ";
                size2++;
            }
            left++;
        }
        cout<<endl;
        
	}
	return 0;
}