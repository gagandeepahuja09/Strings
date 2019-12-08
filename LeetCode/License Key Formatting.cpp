class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string s;
        int k = K;
        for(int i = S.size() - 1; i >= 0; i--) {
            if(S[i] == '-') {
                continue;
            }
            if(S[i] >= 'a' && S[i] <= 'z') {
                s += (S[i]) + ('A' - 'a');
            }
            else {
                s += S[i];
            }
            if(--k == 0) {
                s += "-";
                k = K;
            }
        }
        if(s.back() == '-')
            s.pop_back();
        reverse(s.begin(), s.end());
        return s;
    }
};
