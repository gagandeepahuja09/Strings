string Solution::solve(string A, int B) {
    vector<int> cnt(26, 0);
    for(int i = 0; i < A.size(); i++) {
        cnt[A[i] - 'a']++;
    }
    for(int i = 0; i < A.size(); i++) {
        int n = A[i] - 'a';
        if(cnt[A[i] - 'a'] % 2 == 0) {
            n = ((n % 26 + B % 26) % 26);
        }
        else {
            n = ((n % 26 - B % 26 + 26) % 26);
        }
        A[i] = (char)(n + 'a');
    }
    return A;
}

