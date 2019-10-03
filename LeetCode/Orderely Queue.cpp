class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string ret = S;
        for(int i = 0; i < S.size(); i++) {
            ret = min(ret, S.substr(i) + S.substr(0, i));
        }
        return ret;
    }
};
