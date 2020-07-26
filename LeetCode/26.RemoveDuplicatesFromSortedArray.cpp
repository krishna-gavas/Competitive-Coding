class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> original;
        vector<int> :: iterator it;
        for(it = nums.begin(); it != nums.end(); it++){
            int ele = *it;
            if(find(original.begin(), original.end(), ele) != original.end()){
                nums.erase(it);
                it--;
            }
            else{
                original.push_back(*it);
            }
            
        }
        return nums.size();
    }
};