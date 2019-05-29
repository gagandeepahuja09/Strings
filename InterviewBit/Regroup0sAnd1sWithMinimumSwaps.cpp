int Solution::solve(const string A) {
    int n = A.size();
    int cnt0 = 0, cnt1 = 0;
    vector<int> left(n);
    vector<int> right(n);
    if(A[0] == '0')
        left[0] = 1;
    if(A[n - 1] == '0')
        right[n - 1] = 1;
    for(int i = 1; i < n; i++) {
        if(A[i] == '0') {
            left[i] = 1 + left[i - 1];
        }
        else
            left[i] = left[i - 1];
    }
    for(int i = n - 2; i >= 0; i--) {
        if(A[i] == '0') {
            right[i] = 1 + right[i + 1];
        }
        else
            right[i] = right[i + 1];
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++) {
        // cout << left[i] << " " << right[i] << " ";
        if(A[i] == '1') {
            ans1 += left[i];
            ans2 += right[i];
        }
    }
    // cout << ans1 << " " << ans2 << " ";
    return min(ans1, ans2);
}
