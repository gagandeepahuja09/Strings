/*
Starting indices of the substrings in string

Given a string A and list of words B(words in B are of same length).

Find and return the starting indices of the substrings in string A, which contains all the words present in list B.

Note:

    The order of words of list B appearing inside string S does not matter.
    Words inside the list B can repeat.*/
    

vector<int> Solution::solve(string A, vector<string> &B) {
    map<string, int> mpB;
    for(int i = 0; i < B.size(); i++) {
        mpB[B[i]]++;
    }
    int sLen = B.size() * B[0].size();
    vector<int> ret;
    int sz = B[0].size();
    for(int i = 0; i < A.size(); i++) {
        int j = i;
        map<string, int> mpA(mpB);
        while(j < A.size() && j - i + 1 <= sLen) {
            string s = A.substr(j, sz);
            mpA[s]--;
            j += sz;
        }
        int cnt = 0;
        for(auto it = mpA.begin(); it != mpA.end(); it++) {
            if(it -> second) {
                cnt++;
            }
        }
        if(!cnt)
            ret.push_back(i);
    }
    return ret;
}

