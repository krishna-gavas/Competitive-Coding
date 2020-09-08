// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255

// The main function that sort the given string arr[] in
// alphabatical order
char* countSort(char arr[]);

// Driver program to test above function
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int n;
        scanf("%ld",&n);
        char arr[n+1];
        scanf("%s",arr);
        printf("%s\n", countSort(arr));
    }
    return 0;
}

// The main function that sort the given string arr[] in
// alphabatical order
// return the sorted char array
char* countSort(char A[])
{
    int count[26]={0};
    int i,j,k=0,len=0;
    for(i=0;A[i]!='\0';i++){
        len++;
        count[A[i] - 'a']++;
    }
    for(i=1;i<26;i++){
        count[i] = count[i] + count[i-1];
    }
    char* out = new char[len+1];
    for(i=0;A[i]!='\0';i++){
        count[A[i] - 'a']--;
        out[count[A[i] - 'a']] = char(A[i]);
    }
    return out;
}