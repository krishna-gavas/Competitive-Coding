class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        // int hlen,nlen;
        // char ch = needle[0];
        // hlen = haystack.length();
        // nlen = needle.length();
        // for(int i=0;i<hlen;i++){
        //     if(haystack[i] == ch){
        //         int flag = 0;
        //         for(int j=0;j<nlen;j++){
        //             if(haystack[i+j] != needle[j]){
        //                 flag = 1;
        //                 break;
        //             }
        //         }
        //         if(flag == 0)
        //             return i;
        //     }
        // }
        int found = haystack.find(needle); 
        if (found != string::npos) 
            return found;
        return -1;
    }
};