class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int out,sum, n = nums.size(),min = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            if( i==0 || nums[i] != nums[i-1]){
                int left = i+1;
                int right = n-1;
                while(left < right){
                    sum = nums[i] + nums[left] + nums[right];
                    if(sum == target)
                        return sum;
                    else if(sum < target)
                        left++;
                    else
                        right--;
                    if( abs(sum - target) < min){
                        out = sum;
                        min = abs(sum - target);
                    }
                }
            }
        }
        return out;
    }
};