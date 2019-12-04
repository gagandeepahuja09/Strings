class Solution {
public:
    int countSegments(string s) {
        int i = 0, cnt = 0;
        while(i < s.size()) {
            bool f = false;
            while(i < s.size() && s[i] != ' ') {
                i++;
                f = true;
            }
            if(f)
                cnt++;
            if(s[i] == ' ')
                i++;
        }
        return cnt;
    }
};
