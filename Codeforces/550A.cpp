#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

int main() {
    //int t;
    //cin >> t;
    //while(t--) {
        string s;
        cin >> s;
        int a = -1, b = -1, c = -1, d = -1;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == 'A' && s[i + 1] == 'B') {
                if(a == -1) {
                    a = i;
                }
                c = i;
            }
            if(s[i] == 'B' && s[i + 1] == 'A') {
                if(b == -1) {
                    b = i;
                }
                d = i;
            }
        }
        bool ok = false;
        if(a != -1 && d != -1 && abs(d - a) > 1) {
            ok = true;
        }
        if(b != -1 && c != -1 && abs(c - b) > 1) {
            ok = true;
        }
        if(ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    // }
}
