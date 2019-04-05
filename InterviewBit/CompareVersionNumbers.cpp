int Solution::compareVersion(string A, string B) {
    string a = "", b = "";
    int i = 0, j = 0;
    while(i < A.size() && j < B.size()) {
        while(i < A.size() && A[i] != '.') {
            if(A[i] == '0') {
                i++;
                continue;
            }
            a += A[i];
            i++;
        }
        while(j < B.size() && B[j] != '.') {
            if(B[j] == '0') {
                j++;
                continue;
            }
            b +=B[j];
            j++;
        }
        if(a != b) {
            if(a.size() == b.size()) {
                return a.compare(b) > 0 ? 1 : -1;
            }
            return a.size() > b.size() ? 1 : -1;
        }
        a = b = "";  
        i++;    j++;
    }
    while(i < A.size() && A[i] == '0')
        i++;
    while(j < B.size() && B[j] == '0')
        j++;
    if(i >= A.size() && j >= B.size())
        return 0;
    return i > j ? 1 : -1;
}

