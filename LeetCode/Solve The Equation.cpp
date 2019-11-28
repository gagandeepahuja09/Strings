class Solution {
public:
    pair<int, int> count(string s) {
        int vals = 0, coeffs = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i == 0 && s[i] == 'x') {
                coeffs++;
            }
            else if(i == 0 && s[i] >= '0' && s[i] <= '9') {
                int num = 0; bool f = false;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    f = true;
                    i++;
                }
                if(s[i] != 'x') {
                    vals += num;
                    i--;
                }
                else {
                    if(!f)
                        num = 1;
                    coeffs += num;
                }
            }
            else if(s[i] == '+' || s[i] == '-') {
                int num = 0, pos = i;
                bool f = false;
                i++;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                    f = true;
                }
                if(i == s.size() || s[i] != 'x') {
                    if(s[pos] == '+')
                        vals += num;
                    else
                        vals -= num;
                    i--;
                }
                else {
                    if(!f)
                        num = 1;
                    if(s[pos] == '+')
                        coeffs += num;
                    else
                        coeffs -= num;
                }
            } 
        }
        return { vals, coeffs };
    }
    
    string solveEquation(string s) {
        string s1, s2;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '=') {
                s1 = s.substr(0, i);
                s2 = s.substr(i + 1);
            }
        }
        int v1, v2, c1, c2;
        auto p1 = count(s1), p2 = count(s2);
        v1 = p1.first, v2 = p2.first, c1 = p1.second, c2 = p2.second;
        // cout << c1 << " " << c2 << " " << v1 << " " << v2 << endl;
        if(v1 == v2 && c1 == c2) {
            return "Infinite solutions";
        }
        if(c1 == c2) {
            return "No solution";
        }
        string ret = "x=";
        int ans = (v2 - v1) / (c1 - c2);
        ret += to_string(ans);
        return ret;
    }
};
