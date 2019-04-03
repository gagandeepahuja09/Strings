string Solution::intToRoman(int A) {
    // In Roman Numerals, we use the largest number 1st
    vector<string> romanNumerals = { "M", "CM", "D", "CD", "C", "XC", 
        "L", "XL", "X", "IX", "V", "IV", "I" };
    vector<int> romanValues = { 1000, 900, 500, 400, 100, 90, 50, 40,
    10, 9, 5 ,4, 1 };    
    string ans = "";
    for(int i=0; i < romanValues.size(); i++) {
        while(A >= romanValues[i]) {
            A -= romanValues[i];
            ans += romanNumerals[i];
        }
    }
    return ans;
}

