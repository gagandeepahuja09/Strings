/*
Reduce the string

Given a string A consisting of lowercase English alphabets. Reduce the string to its shortest length by doing any number of operations (possibly zero). In one operation selects a pair of adjacent letters in the string that match and deletes them. For example the string bcaa is shortened to bc in one operation.

Find and return the string by reducing it to its shortest length. if the resultant string is empty return "empty".*/

string Solution::solve(string A) {
    stack<char> stk;
    for(int i = 0; i < A.size(); i++) {
        if(stk.empty() || stk.top() != A[i]) {
            stk.push(A[i]);
        }
        else
            stk.pop();
    }
    string s;
    while(!stk.empty()) {
        s = stk.top() + s;
        stk.pop();
    }
    return s == "" ? "empty" : s;
}

