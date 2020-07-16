class Solution {
public:
    // 2147483647
    bool isPalindrome(int x) {
        if( x < 0 || x >= 2147483647)
            return false;
        long int num = 0;
        int y = x;
        while(x > 0){
            num = num * 10;
            if( num > 2147483647)
                return false;
            num = num + (x % 10);
            x = x / 10;
        }
        if(num == y)
            return true;
        else
            return false;
    }
};