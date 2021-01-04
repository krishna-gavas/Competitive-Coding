// Spirally traversing a matrix

// Question:
// Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.

// Input: 
// The first line of the input contains a single integer T, denoting the number of test cases. Then T test cases 
// follow. Each testcase has 2 lines. First line contains M and N respectively separated by a space. Second line 
// contains M*N values separated by spaces.

// Output:
// Elements when travelled in Spiral form, will be displayed in a single line.

// Example:
// Input:
// 2
// 4 4
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// 3 4
// 1 2 3 4 5 6 7 8 9 10 11 12

// Output:
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
// 1 2 3 4 8 12 11 10 9 5 6 7

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > A, int R, int C) 
    {
        vector<int> spiral;
        int left,right,top,bottom,size1=R*C,size2=0;
        top = 0;
        bottom = R-1;
        left = 0;
        right = C-1;
        
        while(size2 < size1){
            for(int i=left;i<=right && size2 < size1;i++){
                spiral.push_back(A[top][i]);
                size2++;
            }
            top++;

            for(int i=top;i<=bottom && size2 < size1;i++){
                spiral.push_back(A[i][right]);
                size2++;
            }
            right--;

            for(int i=right;i>=left && size2 < size1;i--){
                spiral.push_back(A[bottom][i]);
                size2++;
            }
            bottom--;

            for(int i=bottom;i>=top && size2 < size1;i--){
                spiral.push_back(A[i][left]);
                size2++;
            }
            left++;
        }
        return spiral;
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}