int jumpingOnClouds(vector<int> c) {
    int count=0;
    for(int i=0;i<c.size();){
        if(i+2 == c.size()){
            count = count+2;
            break;
        }
        else if(c[i+2] == 0)
            i=i+2;
        else
            i=i+1;
        count++;
    }
    return count-1;
}