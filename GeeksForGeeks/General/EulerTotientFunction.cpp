// Bit Difference

// Question
// You are given two numbers A and B. Write a program to count number of bits needed to be 
// Euler Totient Function

// Question:
// Euler Totient Function (ETF) Φ(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively 
// prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
// Each test case contains an integer n.

// Output:
// Print the Euler Totient Function Φ(n) for an input n.

// Example:
// Input:
// 2
// 11
// 16

// Output:
// 10
// 8

// Solution: 
// Φ(n) = n-1 if n is prime 
// if n = p1^a1 * p2^a2 * ... pk^ak where p1,p2,... are prime factors of n then 
// Φ(n) = n * (p1-1)/p1 * (p2-1)/p2 * .... (pk-1)/pk

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,totient;
	    cin>>N;
        totient = N;
        for(int i=2;i*i <= N; i++){
            if(N % i == 0){
                totient = totient/i;
                totient = totient * (i-1);

                while(N % i == 0)           // to completely remove p1 which is a1 times
                    N = N / i;
            }
        }
        if(N > 1){
                totient = totient/N;
                totient = totient * (N-1);
        }
		cout<<totient<<endl;
	}
	return 0;
}