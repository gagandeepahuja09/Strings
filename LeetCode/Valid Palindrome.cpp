class Solution {
public:
    bool isPal(string s, int i, int j) {
        while(i < j) {
            if(!isalnum(s[i])) {
                i++;
            }
            else if(!isalnum(s[j])) {
                j--;
            }
            else {
                if(tolower(s[i]) != tolower(s[j]))    return false;
                i++; j--;
            }
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        return isPal(s, 0, s.size() - 1);
    }
};
