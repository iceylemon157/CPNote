int f[maxn];
inline void kmp_build(string s) {
    f[0] = -1;
    for (int i = 1, j = -1; i < (int)s.size(); i ++) {
        while(j != -1 and s[i] != s[j + 1]) j = f[j];
        if(s[i] == s[j + 1]) j ++;
        f[i] = j;
    }
    // for (int i = 0; i < (int)s.size(); i ++) cout << f[i] << ' '; cout << endl;
}
inline int count(string a, string b) {
    // b: the one the one with failure function
    // b: find b in a
    int cnt = 0;
    for (int i = 0, j = -1; i < (int)a.size(); i ++) {
        while (j != -1 and a[i] != b[j + 1]) j = f[j];
        if (a[i] == b[j + 1]) j ++;
        if (j == (int)b.size() - 1) j = f[j], cout << i + 2 - sz(b) << endl, cnt ++;
    }
    return cnt;
}