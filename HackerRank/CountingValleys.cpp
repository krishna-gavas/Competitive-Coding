int countingValleys(int n, string s) {
    int val = 0;
    stack<char> stk;
    for(int i=0;i<s.length();i++){
        if(i==0 || stk.empty()|| (stk.top() == s[i]))
            stk.push(s[i]);
        else {
            stk.pop();
        }
        if(stk.empty() && s[i]=='U')
            val++;
    }
    return val;
}