void Solution::reverseWords(string &A) {
reverse(A.begin(), A.end());
int start = 0, end = 0;
for(int i=0; i<A.size(); i++) {
    if(A[i] == ' ' || i == A.size() - 1) {
        if(i == A.size() - 1)
            end++;
        reverse(A.begin() + start, A.begin() + end);
        start = i + 1;
    }
    end++;
}
}


