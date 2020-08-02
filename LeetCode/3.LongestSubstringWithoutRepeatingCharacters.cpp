class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int len = str.length();
        int max = 0, curlen = 0;
        vector<char> v1;
        vector<char> :: iterator it,it1;
        
        for(int i=0;i<len;i++){
            it = find(v1.begin(), v1.end(), str[i]);
            if(it != v1.end()){
                int count = 1;
                it1 = v1.begin();
                
                while(it1 != it){
                    it1++;
                    count++;
                }
                if(it == v1.begin())
                    v1.erase(it);
                else
                    v1.erase(v1.begin(), ++it);
                v1.push_back(str[i]);
                curlen++;
                curlen = curlen - count;
            }
            else{
                v1.push_back(str[i]);
                curlen++;
            }
            if(curlen > max)
                max = curlen;
        }
        return max;
    }
};