string Solution::convert(string A, int B) {
    int n = A.size(), i = 0;
    vector<vector<char>> mp(B);
    while(i < n) {
        for(int k = 0; k < B; k++) {
            mp[k].push_back(A[i]); 
            i++;
            if(i >= n)
                break;
        }
        if(i >= n)
            break;
        for(int k = B - 2; k > 0; k--) {
            mp[k].push_back(A[i]);    
            i++;
            if(i >= n)
                break;
        }
    }
    string res = "";
    for(int i=0; i<B; i++) {
        for(int j = 0; j < mp[i].size(); j++)
            res += mp[i][j];
         //res += " ";    
    }
    return res;
}

