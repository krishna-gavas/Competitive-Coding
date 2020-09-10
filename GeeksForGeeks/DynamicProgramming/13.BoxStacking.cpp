// Box Stacking

// Question:
// You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. 
// You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of 
// another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D 
// base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also 
// allowable to use multiple instances of the same type of box. You task is to complete the function maxHeight 
// which returns the height of the highest possible stack so formed.
 

// Note: Base of the lower box should be strictly larger than that of the new box we're going to place. This is in 
// terms of both length and width, not just in terms of area. So, two boxes with same base cannot be placed one over 
// the other.

// Input:
// n = 4
// height[] = {4,1,4,10}
// width[] = {6,2,5,12}
// length[] = {7,3,6,32}
// Output: 60

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxHeight() which takes 
// three arrays height[], width[], length[], and N as a number of boxes and returns the highest possible stack 
// height which could be formed.

// Solution:
// Create a box structure with length,width,height and area.
// int maxHeight(h,l,w n): create an array b[3*n] of box structure and initialize j to 0 
//     for(i=0 to n): insert l,w,h and surface area such that l > w and increment j 3 times accordingly
//     sort the b[] array in descending order and create a max[3*n] array and initialize it with heights
//     initialize ans = 0 
//     for(i=1 to 3*n): make high = max[i]
//         for(j=0 to i-1):
//             if(length and width of b[j] > length and width of b[i])
//                 if(max[i] + max[j] > high) then high = max[i] + max[j] and res[i] = res[j]
//         if(high > ans) then ans = high 
//         max[i] = high 
//     return ans 


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct box{
    int area;
    int length;
    int width;
    int height;
};

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        

        int A[1000],B[1000],C[10001];
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            A[i]=a;
            B[i]=b;
            C[i]=c;
        }
        cout<<maxHeight(A,B,C,n)<<endl;
    }
 
} 

bool compareVal(box i1, box i2) 
{ 
    return (i1.area > i2.area); 
}
/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
int maxHeight(int h[],int w[],int l[],int n)
{
    // vector<vector<int> > box(n, vector<int>(4, 0)
    struct box b[3*n];
    int j=0;
    for(int i=0;i<n;i++){
        int temp[3];
        temp[0]=h[i];
        temp[1]=w[i];
        temp[2]=l[i];
        sort(temp,temp+3);
        b[j].length = temp[2];
        b[j].width = temp[1];
        b[j].height = temp[0];
        b[j].area = temp[1]*temp[2];
        j++;
        b[j].length = temp[2];
        b[j].width = temp[0];
        b[j].height = temp[1];
        b[j].area = temp[0]*temp[2];
        j++;
        b[j].length = temp[1];
        b[j].width = temp[0];
        b[j].height = temp[2];
        b[j].area = temp[0]*temp[1];
        j++;
    }
    sort(b,b+(3*n),compareVal);
    int max[3*n],res[3*n];
    for(int i=0;i<(3*n);i++){
        max[i] = b[i].height;
        res[i] = i;
    }
    int ans=0;
    for(int i=1;i<(3*n);i++){
        int high =max[i];
        for(int j=0;j<i;j++){
            if((b[j].length > b[i].length) && (b[j].width > b[i].width)){
                if(max[i] + max[j] > high){
                    high = max[i] + max[j];
                    res[i] = res[j];
                }
            }
        }
        if(high > ans)
            ans = high;
        max[i] = high;
    }
    return ans;
}