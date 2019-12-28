class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        vector<int> kmp(b.size() + 1);
        for(int i = 1, j = 0; i < b.size(); ) {
            if(b[i] == b[j]) {
                kmp[i++] = ++j;
            }
            else {
                if(j == 0)
                    i++;
                else
                    j = kmp[j - 1];
            }
        }
        for(int i = 0, j = 0; i < a.size(); i++, j = j ? kmp[j - 1] : 0) {
            while(j < b.size() && a[(i + j) % a.size()] == b[j]) {
                ++j;
            }
            if(j == b.size())
                return ceil((float)(i + j) / a.size());
        }
        return -1;
    }
};
