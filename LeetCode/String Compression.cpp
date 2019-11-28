class Solution {
public:
    int compress(vector<char>& chars) {
        int pos = 0;
        for(int i = 0; i < chars.size();) {
            char c = chars[i], cnt = 0;
            while(i < chars.size() && chars[i] == c) {
                cnt++;
                i++;
            }
            if(cnt == 1) {
                chars[pos] = c;
                pos++;
            }
            else {
                chars[pos] = c;
                pos++;
                string scnt = to_string(cnt);
                for(int j = 0; j < scnt.size(); j++) {
                    chars[pos] = scnt[j];
                    pos++;
                }
            }
        }
        return pos;
    }
};
