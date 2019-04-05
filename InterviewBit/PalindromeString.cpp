int Solution::isPalindrome(string A) {
string s = "";
for(int i = 0; i < A.size(); i++) {
    if(A[i] >= '1' && A[i] <= '9')
        s += A[i];
    if((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A') && A[i] <= 'Z') {
        if(A[i] >= 'a' && A[i] <= 'z')
            s += A[i];
        else
            s += (A[i] + 'a' - 'A');
    }
}
int l = 0, r = s.size() - 1;
while(l < r) {
    if(s[l] != s[r])
        return false;
    l++;    r--;    
}
return true;
}


