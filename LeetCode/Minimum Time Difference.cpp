class Solution {
public:
    int findMinDifference(vector<string>& t) {
        vector<int> times;
        for(string s : t) {
            string min, h;
            bool flag = false;
            for(char c : s) {
                if(c == ':')
                    flag = true;
                else if(flag)
                    min += c;
                else
                    h += c;
            }
            int minute = stoi(min) + (60 * stoi(h)); 
            times.push_back(minute);
        }
        sort(times.begin(), times.end());
        int ans = min(1440 - (times.back() - times[0]), (times.back() - times[0]));
        for(int i = 1; i < times.size(); i++) {
            int d = times[i] - times[i - 1];
            ans = min(ans, min(1440 - d, d));
        }
        return ans;
    }
};
