int Solution::solve(string A) {
    string rev = A;
    reverse(rev.begin(), rev.end());
    A = A + '$' + rev;
    int n = A.size();
    int lps[n];
    int i = 1, j = 0;
    lps[0] = 0;
    while(i < n) {
        if(A[i] == A[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else if(j != 0) {
            j = lps[j - 1];
            
        }
        else {
            lps[i] = 0;
            i++;
        }
    }
    return rev.size() - lps[n - 1];
}

