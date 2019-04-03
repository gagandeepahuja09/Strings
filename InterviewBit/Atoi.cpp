int Solution::atoi(const string A) {
    if(!A.size())
        return 0;
    int i = 0, negative = 0;
    long ans = 0;
    // (1) Case of extra space => Ignore them
    while(A[i] == ' ') {
        i++;
        if(i == A.size())
            return 0;
    }
    
    if(!isdigit(A[i])) {
        // (2) Case of any character other than digit, + or -
        if(A[i] != '+' || A[i] != '-')
            return 0;
        else {
            if(i >= A.size() - 1)
                return 0;
            // (3) Case of more than 1 + or -    
            if(!isdigit(A[i] + 1))
                return 0;
            i++;    
        }    
    }
    // (4) Case of negative number
    if(i != 0) {
        if(A[i - 1] == '-')
            negative = 1;
    }
    while(i < A.size()) {
        if(!isdigit(A[i]))
            break;
        ans = ans * 10 + (A[i] - '0');
        cout << ans;
        if(ans >= INT_MAX)
            break;
        i++;    
    }
    if(negative)
        ans = -ans;
    
    // (5) Case of overflow from INT_MAX or INT_MIN
    if(ans > INT_MAX)
        return INT_MAX;
    if(ans < INT_MIN)
        return INT_MIN;
        
    return (int)ans;    
}

