class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<int> :: iterator it;
        for(int i=0; i< nums.size(); i++){
            int ele = target - nums[i];
            it = find(nums.begin(), nums.end(), ele);
            if(it != nums.end()){ // found
                if((it - nums.begin()) == i)
                    continue;
                ret.push_back(i);
                ret.push_back(it - nums.begin());
                return ret;
            }
        }
        return ret;
    }
};