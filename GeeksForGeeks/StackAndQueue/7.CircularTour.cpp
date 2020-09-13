// Circular tour

// Question:
// Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol 
// in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

// Input:
// N = 4
// Petrol = 4 6 7 4
// Distance = 6 5 3 5
// Output: 1

// Your Task:
// Your task is to complete the function tour() which takes the required data as inputs and returns an integer 
// denoting a point from where a truck will be able to complete the circle (The truck will stop at each petrol pump 
// and it has infinite capacity). If there exists multiple such starting points, then the function must return the 
// first one out of those. (return -1 otherwise)

#include <iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

// O(n^2) solution
// int tour(petrolPump p[],int n)
// {
//     int totalp, totald, count, flag;
//     for(int i=0;i<n;i++){
//         totalp = 0;
//         totald = 0;
//         count = 0;
//         int j = i;
//         flag = 0;
//         while(totalp >= totald && count<n){
//             totalp += p[j].petrol;
//             totald += p[j].distance;
//             count++;
//             j = (j+1)%n;
//             flag = 1;
//         }
//         if(i == j && flag == 1 && totalp >= totald)
//             return i;
//     }
//     return -1;
// }

// O(n) solution
// tour: initialize start=0, end=1 and bal = petrol[start] - distance[start]
//     while(end != start or bal < 0):
//         while (bal < 0 and start != end):
//             bal = bal - (petrol[start] - distance[start])
//             start = (start + 1) % n
//             if(start is 0) then return -1
//         bal = bal + (petrol[end] - distance[end])
//         end = (end + 1) % n
//     return start

int tour(petrolPump p[],int n)
{
    int start = 0; 
	int end = 1; 
	int bal = p[start].petrol - p[start].distance; 
	while (end != start || bal < 0){ 
		while (bal < 0 && start != end){ 
			bal =bal - (p[start].petrol - p[start].distance); 
			start = (start + 1) % n; 

			if (start == 0) 
			return -1; 
		} 
		bal = bal + (p[end].petrol - p[end].distance); 
		end = (end + 1) % n; 
	} 
	return start;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    petrolPump p[n];

	    for(int i=0;i<n;i++)
	        cin>>p[i].petrol>>p[i].distance;

        cout<<tour(p,n)<<"\n";
	}
	return 0;
}