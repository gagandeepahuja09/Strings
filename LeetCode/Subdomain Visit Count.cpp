class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        for(auto s : cpdomains) {
            string s1 = ""; int cnt = 0;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == ' ') {
                    cnt = stoi(s1);
                    s1 = s.substr(i + 1);
                    break;
                }
                else
                    s1 += s[i];
            }
            mp[s1] += cnt;
            for(int i = 0; i < s1.size(); i++) {
                if(s1[i] == '.') {
                    mp[s1.substr(i + 1)] += cnt;
                }
            }
        }
        vector<string> ret;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            ret.push_back(to_string(it -> second) + " " + it -> first);
        }
        return ret;
    }
};
