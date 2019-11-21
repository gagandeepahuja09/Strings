class Solution {
public:
    bool checkValidString(string s) {
        int cmax = 0, cmin = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                cmax++, cmin++;
            if(s[i] == ')')
                cmax--, cmin = max(0, cmin - 1);
            if(s[i] == '*')
                cmax++, cmin = max(0, cmin - 1);
            if(cmax < 0)
                return false;
        }
        return (cmin == 0);
    }
};
