/*Divisibility by 8

Given a number A in the form of string. Check if the number is divisible by 8 or not.
*/

int Solution::solve(string A) {
    int n = A.size(), num = 0;
    for(int i = n - 3; i < n; i++) {
        num = num * 10 + A[i];
    }
    return (num % 8 == 0);
}

