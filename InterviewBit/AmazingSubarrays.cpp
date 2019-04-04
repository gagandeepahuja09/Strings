int Solution::solve(string A) {
    int n = A.size(), ans = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'o' || A[i] == 'i' ||
        A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || 
        A[i] == 'O' || A[i] == 'U') {
            ans = (ans % 10003 + (n - i) % 10003) % 10003;
        }
    }
    return ans % 10003;
}

