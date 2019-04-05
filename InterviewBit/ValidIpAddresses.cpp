/*void ipAddresses(string A, vector<string>& res, string str, int cnt = 4) {
    cout << str << " ";
    if(!A.size()) {
        if(cnt == 0)
            res.push_back(str);
        return;
    }
    string a = "";
    int i = 0;
    while(A[i] != '.') {
        a += A[i];
        if((a.size() > 1 && a[0] == '0') || a > "255") {
            i++;
            continue;
        }
        if(cnt > 1)    
            ipAddresses(A.substr(i), res, str + a + '.', cnt - 1);
        else if(cnt == 1)
            ipAddresses(A.substr(i), res, str + a, cnt - 1);
        i++;    
    }
}*/

bool isValid(string ip) {
    int i = 0, n = ip.size();
    while(i < n) {
        int j = i;
        while(j < n && ip[j] != '.') {
            j++;
        }
        if(j - i > 3 || j - i == 0)
            return false;
        int num = stoi(ip.substr(i, j - i + 1));
        if(num > 255)
            return false;
        if(j - i > 1 && (num == 0 || ip[i] == '0'))
            return false;
        i = j + 1;    
    }
    return true;
}

string generateIp(string A, int i, int j, int k) {
    string ip = "";
    for(int l =0; l < A.size(); l++) {
        ip += A[l];
        if(l == i || l == j || l == k)
            ip += '.';
    }
    return ip;
}

vector<string> Solution::restoreIpAddresses(string A) {
    int n = A.size();
    vector<string> res;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n - 1; k++) {
                string ip = generateIp(A, i, j, k);
                if(isValid(ip))
                    res.push_back(ip);
            }
        }
    }
    return res;
}

