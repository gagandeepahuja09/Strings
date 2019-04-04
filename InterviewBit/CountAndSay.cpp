string Solution::countAndSay(int N) {
    string curr = "1";
    for(int i = 1; i < N; i++) {
        int cnt = 1;
        int sz = curr.size();
        string res = "";
        for(int l = 0; l < sz; l++) {
            while(l < sz - 1 && curr[l] == curr[l + 1]) {
                cnt++;
                l++;
            }
            res += (cnt + '0');
            res += curr[l];
            cnt = 1;
        }
        curr = res;
    }
    return curr;
}

