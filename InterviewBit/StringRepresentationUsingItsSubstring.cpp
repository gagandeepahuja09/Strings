
String representation using its substring

Given a String consisting of lowercase English alphabets A, Find if the given string can be represented from a substring by iterating the substring two or more times.
Input Format

The only argument given is String A.

Output Format

Return 1 if the given string can be represented from a substring by iterating the substring two or more times
else return 0.

Constraints

1 <= length of the string <= 100000

For Example

Input 1:
    A = "abcabcabc"
Output 1:
    1

Input 2:
    A = "abcdabc"
Output 2: 
    0

int Solution::solve(string A) {
    int n = A.size();
    string s = A;
    A += A;
    string text = A.substr(1, A.size() - 2);
    if(text.find(s) != string::npos)
        return 1;
    return 0;
}

