long repeatedString(string s, long n) {
    long count=0,count1=0;
    int len = s.length();
    int div = n % len;
    for(int i=0;i<len;i++){
        if(s[i] == 'a'){
            count++;
            if(i < div)
                count1++;
        }
    }
    count = count * (n / len);
    count = count + count1;
    return count;
}