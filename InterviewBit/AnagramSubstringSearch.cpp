/*
Anagram Substring Search

Given a string A and a string B.

Find and return the starting indices of the substrings of A which matches any of the anagrams of B.*/

vector<int> Solution::solve(string A, string B) {
    vector<int> pat(256, 0);
    vector<int> text(256, 0);
    int k = B.size();
    vector<int> res;
    for(int i = 0; i < B.size(); i++) {
        pat[B[i]]++;
    }
    for(int i = 0; i < k; i++) {
        text[A[i]]++;
    }
    bool flag = true;
    for(int i = 0; i < 256; i++) {
        if(pat[i] != text[i])
            flag = false;
    } 
    if(flag)
        res.push_back(0);
    for(int i = k; i < A.size(); i++) {
        text[A[i - k]]--;
        text[A[i]]++;
        bool flag = true;
        for(int j = 0; j < 256; j++) {
            if(pat[j] != text[j])
                flag = false;
        }
        if(flag)
            res.push_back(i - k + 1);
    }
    return res;
}

