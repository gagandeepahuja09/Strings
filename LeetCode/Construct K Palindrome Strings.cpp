class Solution {
public:
    bool canConstruct(string s, int k) {
        int mn, mx = s.size();
        vector<int> c(26, 0);
        int odd = 0, even = 0;
        for(int i = 0; i < s.size(); i++) {
            c[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
           if(c[i]) {
               if(c[i] % 2)
                   odd++;
               else
                   even++;
           }
        }
        mn = odd;
        return (k <= mx && k >= mn);
    }
};
