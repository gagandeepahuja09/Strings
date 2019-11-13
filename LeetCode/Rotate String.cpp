class Solution {
public:
    bool rotateString(string A, string B) {
        if(A == "" && B == "")
            return true;
        int n = A.size();
        A += A;
        for(int i = 0; i < A.size() - n; i++) {
            if(A.substr(i, n) == B) {
                return true;
            }
        }
        return false;
    }
};
