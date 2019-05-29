string Solution::intToRoman(int A) {
    vector<pair<int, string>> v = { { 1000, "M" }, { 900, "CM" }, { 500, "D"}, 
    { 400, "CD" }, { 100, "C" }, { 90, "XC"}, { 50, "L"}, { 40, "XL" }, 
    { 10, "X"}, { 9, "IX" }, { 5, "V"}, {4, "IV"}, { 1, "I" } };
    int i = 0;
    string s;
    while(A && i < v.size()) {
        while(v[i].first <= A && A) {
            A -= v[i].first;
            s += v[i].second;
        }
        i++;
    }
    return s;
}

