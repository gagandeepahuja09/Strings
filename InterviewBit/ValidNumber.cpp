int Solution::isNumber(const string A) {
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, posDot = -1, posE = -1, 
    posNeg = -1;
    int n = A.size();
    for(int i = 0; i < n; i++) {
        if((A[i] < '0' || A[i] > '9') && A[i] != 'e' && 
        A[i] != '.' && A[i] != ' ' && A[i] != '-') {
            return false;
        }
        if(A[i] >= '0' && A[i] <= '9')
            c4++;
        if(A[i] == '.') {
            c1++;
            if(i == n - 1 || (A[i + 1] < '0' || A[i + 1] > '9'))
                return false;
            posDot = i;
        }
        if(A[i] == 'e') {
            c2++;
            posE = i;
        }
        if(A[i] == '-') {
            c3++;
            posNeg = i;
        }
        if(c1 > 1 || c2 > 1 || posDot == n - 1 || posE == n - 1 
        || (posDot > posE && posE != -1) || (c3 > 1 && posNeg < posE) 
        || c3 > 2 || (posNeg > 0 && posE == -1)) {
            return false;
        }
    }
    return (c4 > 0);
}

