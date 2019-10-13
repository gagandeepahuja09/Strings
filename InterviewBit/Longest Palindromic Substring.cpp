string Solution::longestPalindrome(string A) {
    int n = A.size(), mx = 1, start = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++)
        dp[i][i] = true;
    bool flag = false;
    for(int i = 0; i < n - 1; i++) {
        if(A[i] == A[i + 1]) {
            if(!flag) {
                flag = true;
                start = i;
                mx = 2;
            }
            dp[i][i + 1] = true;
        }
    }
    for(int len = 1; len < n; len++) {
        for(int i = 0; i + len < n; i++) {
            int j = i + len;
            if(A[i] == A[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if(len + 1 > mx) {
                    mx = len + 1;
                    start = i;
                }
            }
        }
    }
    return A.substr(start, mx);
}

