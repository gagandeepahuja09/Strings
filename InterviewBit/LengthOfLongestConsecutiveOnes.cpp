/*
Length of longest consecutive ones

Given a binary string A. It is allowed to do at most one swap between any 0 and 1. Find and return the length of the longest consecutive 1’s that can be achieved.*/

int Solution::solve(string A) {
    int maxc = 0, c1 = 0, n = A.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    if(A[0] == '1')
        left[0] = 1;
    if(A[n - 1] == '1')
        right[n - 1] = 1;
    for(int i = 1; i < n; i++) {
        if(A[i] == '1')
            left[i] = 1 + left[i - 1];
        else
            left[i] = 0;
    }
    for(int i = n - 2; i >= 0; i--) {
        if(A[i] == '1')
            right[i] = 1 + right[i + 1];
        else
            right[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        if(A[i] == '1')
            c1++;
    }
    for(int i = 1; i < n - 1; i++) {
        if(A[i] == '0') {
            int c = left[i - 1] + right[i + 1];
            if(c < c1)
                c++;
            maxc = max(maxc, c);    
            // cout << left[i - 1] << " " << right[i + 1] << " x ";
        }
    }
    return maxc;
}

