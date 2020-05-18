// Find median in a stream

// Create 2 heaps namely maxHeap for storing elements less than median and minHeap for elements greater than median
// for i=0 to N input X 
// if(i == 0) then med1 = X, print X as median and push X to maxHeap 
// if(i == 1) then 
//     if(X > med1) make med2 = X and push X to minHeap else make med2 = med1, med1 = X push X to maxHeap and pop med2 from maxHeap and push to minHeap
//     median = (med1 + med2)/2 and print median
// if( i != 0 && i != 1): med1 = maxHeap.front()
//     if(X > med1) then push X to minHeap else push X to maxHeap.
//     if(difference of size of minHeap and maxHeap > 1) then 
//         if(maxHeapSize > minHeapSize) then pop maxHeap.front() and push it to minHeap else pop minHeap.front() and push it to makeHeap
//     if(difference of size of minHeap and maxHeap == 1) then
//         if (maxHeap.size() > minHeap.size() ) then median = med1 else median = med2
//     else median = (med1 + med2)/2;
// finally print median


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N,X,median,med1,med2;
    cin>>N;
    vector<int> maxHeap,minHeap;
	for(int i=0;i<N;i++){
	    cin>>X; 
        if(i == 0){
            cout<<X<<"\n";
            med1 = X;
            median = X;
            maxHeap.push_back(X);
            make_heap(maxHeap.begin(), maxHeap.end());
            continue;
        }   
        if(i == 1){
            if(X > med1){
                med2 = X;
                minHeap.push_back(X);
                make_heap(minHeap.begin(), minHeap.end(), greater<int>());
            }
            else{
                med2 = med1;
                med1 = X;
                minHeap.push_back(med2);
                make_heap(minHeap.begin(), minHeap.end(), greater<int>());
                pop_heap(maxHeap.begin(), maxHeap.end()); 
                maxHeap.pop_back();
                maxHeap.push_back(med1);
                push_heap(maxHeap.begin(), maxHeap.end());
            }
            median = (med1 + med2)/2;
            cout<<median<<endl;
            continue;
        }
        med1 = maxHeap.front();
        if(X > med1){   
            minHeap.push_back(X);
            push_heap(minHeap.begin(), minHeap.end(), greater<int>());
        }
        else{
            maxHeap.push_back(X);
            push_heap(maxHeap.begin(), maxHeap.end());
        }

        if(abs(int(maxHeap.size() - minHeap.size())) > 1){
            if(maxHeap.size() > minHeap.size()){
                minHeap.push_back(maxHeap.front());
                push_heap(minHeap.begin(), minHeap.end(), greater<int>());
                pop_heap(maxHeap.begin(), maxHeap.end()); 
                maxHeap.pop_back();
            }
            else{
                maxHeap.push_back(minHeap.front());
                push_heap(maxHeap.begin(), maxHeap.end());
                pop_heap(minHeap.begin(), minHeap.end(), greater<int>()); 
                minHeap.pop_back();
            }
        }
        med1 = maxHeap.front();
        med2 = minHeap.front();
        
        if(abs(int(maxHeap.size() - minHeap.size())) == 1){
            if(maxHeap.size() > minHeap.size())
                median = med1;
            else 
                median = med2;
        }
        else{
            median = (med1 + med2)/2;
        }
        cout<<median<<endl;
        
    }	
    
	return 0;
}