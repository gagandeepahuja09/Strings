string Solution::addBinary(string A, string B) {
    int carry = 0, i = A.length() - 1, j = B.length() - 1;
    string res = "";
    while(i >= 0 || j >= 0 || carry == 1) {
        carry += (i >= 0) ? A[i] - '0' : 0;
        carry += (j >= 0) ? B[j] - '0' : 0;
        // 1 or 3 => add 1 else add 0
        res = (char)(carry % 2 + '0') + res;
        carry = carry / 2;
        i--; j--;
    }
    return res;
}

