vector<int> z;
inline void buildz(string s) {
    int n = s.size();
    z.clear();
    z.resize(n);
    z[0] = n;
    int l = 0, r = n - 1;
    for(int i = 1; i < (int)s.size(); i ++) {
        z[i] = max(min(z[i - l], r - i), 0ll);
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]) {
            l = i, r = i + z[i], z[i] ++;
        }
    }
}
inline int count(string a, string b) {
    // how many times does b exists in a
    string s = b + "$" + a;
    int cnt = 0;
    buildz(s);
    for(int i = 0; i < (int)s.size(); i ++) {
        if(z[i] == (int)b.size()) cnt ++;
    }
    return cnt;
}
