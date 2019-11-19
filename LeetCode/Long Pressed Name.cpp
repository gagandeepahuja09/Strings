class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j = 0;
        for(int i = 0; i < name.size();) {
            char curr = name[i];
            int c1 = 0, c2 = 0;
            while(name[i] == curr) {
                i++;
                c1++;
            } 
            while(typed[j] == curr) {
                j++;
                c2++;
            }
            if(c1 > c2)
                return false;
        }
        return (j == typed.size());
    }
};
