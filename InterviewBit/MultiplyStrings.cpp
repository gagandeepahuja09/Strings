string Solution::multiply(string A, string B) {
    if(A == "0" || B == "0")
        return "0";
    int aL = A.length(), bL = B.length();    
    vector<int> result(aL + bL, 0);
    string res = "";
    
    for(int i = aL - 1; i >= 0; i--) {
        for(int j = bL - 1; j >= 0; j--) {
            result[i + j + 1] += (A[i] - '0') * (B[j] - '0');
        }
    }
    
    for(int k = aL + bL - 1; k >= 0; k--) {
        if(result[k] >= 10) {
            result[k - 1] += result[k] / 10;
            result[k] %= 10;
        }
    }
    
    int cnt = 0;
    // Remove leading zeroes
    for(int i = 0; i < result.size(); i++) {
        if(result[i] == 0 && i == cnt)
            cnt++;
        else
            res += (result[i] + '0');
    }
    return res;
}

