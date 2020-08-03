class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0, left = 0, right = height.size() - 1;
        while( left < right){
            int area;
            if(height[left] < height[right]){
                area = height[left] * (right - left);
                left++;
            }
            else{
                area = height[right] * (right - left);
                right--;
            }
            if(area > water)
                water = area;
        }
        return water;
    }
};