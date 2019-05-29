/*
Same Format String

Given two strings A and B, check if B contains same characters as that of given string A and in the same order.

Example:

Input:
A = "HIRED"
B = "HHHIIIRRRRREEEEEDDDDD"
Output:
1

Input:
A = "HIRED"
B = "DDHHHHIIIIRRRRREEEEDDD"
Output:
0

*/

int Solution::solve(const string A, const string B) {
    int i = 0, j = 0;
    while(i < A.size() && j < B.size() - 1) {
        if(A[i] == B[j] && B[j] == B[j + 1]) {
            j++;
        }
        else if(A[i] == B[j]) {
            i++; j++;
        }
        else
            return 0;
    }
    if(i == A.size() - 1 && A[i] == B[j])
        i++, j++;
    return (i == A.size() && j == B.size());    
}

