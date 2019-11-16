class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(int i = 0; i < moves.size(); i++) {
            if(moves[i] == 'U')
                x++;
            if(moves[i] == 'D')
                x--;
            if(moves[i] == 'L')
                y++;
            if(moves[i] == 'R')
                y--;
        }
        return (x == 0 && y == 0);
    }
};
