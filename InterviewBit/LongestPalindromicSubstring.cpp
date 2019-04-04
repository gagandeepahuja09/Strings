string Solution::longestPalindrome(string A) {
    int maxPal = 1, start = 0;
    int n = A.size();
    // Odd length palindromes
    for(int i = 1; i < n; i++) {
        int l = i - 1, r = i + 1;
        while(l >= 0 && r < n && A[l] == A[r]) {
            if(r - l + 1 > maxPal) {
                maxPal = r - l + 1;
                start = l;
            }
            l--;    r++;
        }
    }
    // Even length palindromes
    for(int i = 1; i < n; i++) {
        int l = i - 1, r = i;
        while(l >= 0 && r < n && A[l] == A[r]) {
            if(r - l + 1 > maxPal) {
                maxPal = r - l + 1;
                start = l;
            }
            l--;    r++;
        }
    }
    // cout << start << " " << maxPal;
    return A.substr(start, maxPal);
}

