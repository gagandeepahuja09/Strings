vector<string> Solution::fullJustify(vector<string> &words, int B) {
    vector<string> lines;
    int i = 0;
    while(i < words.size()) {
        int count = words[i].size();
        int j = i + 1;
        while(j < words.size()) {
            if(words[j].size() + 1 + count > B)
                break;
            count += words[j].size() + 1;
            j++;
        }
        string line;
        int diff = j - i - 1;
        // Last line or no. of words b/w them == 0
        if(j == words.size() || diff == 0) {
            for(int k = i; k < j; k++) {
                line += (words[k] + " ");
            }
            line = line.substr(0, line.size() - 1);
            line += string(B - line.size(), ' ');
        }
        else {
            int spaces = (B - count) / (diff);
            int rmder = (B - count) % (diff); 
            for(int k = i; k < j; k++) {
                line += words[k];
                if(k < j - 1) {
                    int limit = spaces + ((k < (rmder + i)) ? 1 : 0);
                    line += string(limit + 1, ' ');
                }
            }
        }
        lines.push_back(line);
        i = j;
    }
    return lines;
}

