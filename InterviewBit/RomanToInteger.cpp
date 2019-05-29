int Solution::romanToInt(string A) {
    map<char, int> mp;
    mp['M'] = 1000;
    mp['D'] = 500;
    mp['C'] = 100;
    mp['L'] = 50;
    mp['X'] = 10;
    mp['V'] = 5;
    mp['I'] = 1;
    int ans = 0;
    for(int i = 0; i < A.size() - 1; i++) {
        int x = mp[A[i]];
        int y = mp[A[i + 1]];
        if(x < y)
            ans -= x;
        else
            ans += x;
    }
    ans += mp[A.back()];
    return ans;
}

