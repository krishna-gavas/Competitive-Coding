int sockMerchant(int n, vector<int> ar) {
    set<int> mySet;
    int count =0;
    for(int i=0;i<n;i++){
        if(mySet.find(ar[i]) != mySet.end()){
            mySet.erase(ar[i]);
            count++;
        }
        else{
            mySet.insert(ar[i]);
        }
    }
    return count;
}