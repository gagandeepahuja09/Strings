class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ret;
        int l = K;
        for(int i = S.size() - 1; i >= 0; i--) {
            if(S[i] == '-')
                continue;
            l--;
            if(l == -1) {
                ret += '-';
                l = K - 1;
            }
            if(S[i] != '-') {
                if(!isalpha(S[i]) || isupper(S[i]))
                    ret += S[i];
                else {
                    ret += (char)(toupper(S[i]));
                }
            }
            // cout << l << endl;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
