class Solution {
public:
    const long BASE = 37, MOD = 1e9 + 7;
    
    void calculateHash(string s, vector<long>& hash, vector<long>& pow) {
        pow[0] = 1;
        for(int i = 1; i <= s.size(); i++) {
            pow[i] = (pow[i - 1] * BASE) % MOD;
            hash[i] = (hash[i - 1] * BASE + s[i - 1]) % MOD;
        }
    }
    
    int getHash(int l, int r, vector<long>& hash, vector<long>& pow) {
        return (hash[r] - hash[l] * pow[r - l] % MOD + MOD) % MOD;
    }
    
    // Rabin Karp
    // Rolling Hash
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        vector<long> hash(n + 1), pow(n + 1);
        calculateHash(text, hash, pow);
        int cnt = 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            for(int len = 2; i + len <= n; len += 2) {
                int mid = i +  len / 2;
                long hash1 = getHash(i, mid, hash, pow);
                long hash2 = getHash(mid, i + len, hash, pow);
                if(hash1 == hash2) {
                    st.insert(hash1);
                }
            }
        }
        return st.size();
    }
};
