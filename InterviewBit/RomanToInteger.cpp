int Solution::romanToInt(string A) {
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    if(A.size() == 1) 
        return mp[A[0]];
    int sum = mp[A[A.length() - 1]];    
    for(int i = A.length() - 2; i >= 0; i--) {
        int x = mp[A[i]], y = mp[A[i + 1]];
        if(x < y)
            sum -= x;
        else
            sum += x;
    }
    return sum;
}

