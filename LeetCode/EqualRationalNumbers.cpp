class Solution {
public:
    double f(string s) {
        auto i = s.find("(");
        if(i != string::npos) {
            string base = s.substr(0, i);
            string repeat = s.substr(i + 1, s.size() - i - 2);
            for(int i = 0; i < 16; i++)
                base += repeat;
            return stod(base);
        }
        return stod(s);
    }
    
    bool isRationalEqual(string S, string T) {
        return f(S) == f(T);    
    }
};
