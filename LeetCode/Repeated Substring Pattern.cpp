class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1, j = 0;
        vector<int> lps(s.size(), 0);
        while(i < s.size()) {
            if(s[i] == s[j])
                lps[i++] = ++j;
            else {
                if(j == 0)
                    lps[i++] = 0;
                else
                    j = lps[j - 1];
            }
        }
        return (lps[s.size() - 1] && s.size() % (s.size() - lps[s.size() - 1]) == 0);
    }
};
