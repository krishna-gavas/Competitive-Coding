class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double med1=0,med2=0,median=0;
        vector<int> maxHeap,minHeap;
        for(int i=0;i<nums1.size();i++){
            if(i == 0){
                med1 = nums1[i];
                median = nums1[i];
                maxHeap.push_back(nums1[i]);
                make_heap(maxHeap.begin(), maxHeap.end());
                continue;
            }
            else if(i == 1){
                med2 = nums1[i];
                minHeap.push_back(nums1[i]);
                make_heap(minHeap.begin(), minHeap.end(), greater<int>());        
                continue;
            }
            med1 = maxHeap.front();
            if(nums1[i] > med1){   
                minHeap.push_back(nums1[i]);
                push_heap(minHeap.begin(), minHeap.end(), greater<int>());
            }
            else{
                maxHeap.push_back(nums1[i]);
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
        }
        
        for(int i=0;i<nums2.size();i++){
            if(i == 0 && nums1.size() == 0){
                med1 = nums2[i];
                median = nums2[i];
                maxHeap.push_back(nums2[i]);
                make_heap(maxHeap.begin(), maxHeap.end());
                continue;
            }

            if(nums2[i] > med1){   
                minHeap.push_back(nums2[i]);
                push_heap(minHeap.begin(), minHeap.end(), greater<int>());
            }
            else{
                maxHeap.push_back(nums2[i]);
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
        }
        
        if(abs(int(maxHeap.size() - minHeap.size())) == 1){
            if(maxHeap.size() > minHeap.size())
                median = med1;
            else 
                median = med2;
        }
        else{
            median = (med1 + med2)/2;
        }
        return median;
    }
};