class Solution {
public:
    string findReplaceString(string s, vector<int>& ind, vector<string>& src, vector<string>& t) {
        map<int, pair<int, string>, greater<int>> mp;
        for(int i = 0; i < ind.size(); i++) {
            if(s.substr(ind[i], src[i].size()) == src[i]) {
                mp[ind[i]] = { src[i].size(), t[i] };
            }
        }
        for(auto &it : mp) {
            s = s.substr(0, it.first) + it.second.second + 
                s.substr(it.first + it.second.first);
        }
        return s;
    }
};
