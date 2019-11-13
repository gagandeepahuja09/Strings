class Solution {
public:
    vector<string> morse = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
    
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        for(int i = 0; i < words.size(); i++) {
            string s = words[i], curr;
            for(int j = 0; j < s.size(); j++) {
                curr += morse[s[j] - 'a'];
            }
            st.insert(curr);
        }
        return st.size();
    }
};
