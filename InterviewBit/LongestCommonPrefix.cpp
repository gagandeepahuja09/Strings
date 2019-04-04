string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size(), minLen = INT_MAX;
    for(int i = 0; i < n; i++) {
        int len = A[i].size();
        minLen = min(minLen, len);
    }
    string res;
    for(int i = 0; i < minLen; i++) {
        char temp = A[0][i];
        int k = 1;
        while(k < n) {
            if(A[k][i] == temp)
                k++;
            else
                return res;
        }
        res += temp;
    }
    return res;
}

