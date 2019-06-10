/*
Check two bracket expressions

Given two strings A and B. Each string represents an expression consisting of lowercase english alphabets,
'+', '-' and '()'. The task is to compare them and check if they are similar. If they are
similar return 1 else return 0.

Note: It may be assumed that there are at most 26 operands from ‘a’ to ‘z’ and every 
operand appears only once.


Input Format

The arguments given are string A and String B.

Output Format

Return 1 if they represent the same expression
else return 0.

Constraints

1 <= length of the each String <= 100

For Example

Input 1:
     A = "-(a+b+c)"
     B = "-a-b-c"
Output 1:
     1

Input 2:
     A = "a-b-(c-d)"
     B = "a-b-c-d"
Output 2:
    0
*/

string change(string A, stack<char>& stk) {
    int minusC = 0;
    stk.push('+');
    string s = "";
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '(') {
            if(i > 0) {
                if(A[i - 1] == '-')
                    minusC++;
                stk.push(A[i - 1]);    
            }
        }
        else if(A[i] == ')') {
            if(!stk.empty() && stk.top() == '-')
                minusC--;
        }
        else if(A[i] != '+' && A[i] != '-') {
            s += A[i];
        }
        else {
            if(minusC % 2) {
                if(s[i] == '+')
                    s += '-';
                else
                    s += '+';
            }
            else
                s += A[i];
        }
    }
    return s;
    // cout << s << " ";
}

int Solution::solve(string A, string B) {
    stack<char> stk1;
    stack<char> stk2;
    string s1 = change(A, stk1);
    string s2 = change(B, stk2);
    return (s1 == s2);
}

