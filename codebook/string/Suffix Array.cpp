const int mxN = 1e5 + 50;
string s;
int sa[mxN], tmp[2][mxN], c[mxN];
int rk[mxN], lcp[mxN];
void GetSA() {
    int *x = tmp[0], *y = tmp[1], m = 256, n = s.size();
    // x = 前半字典序的 sort, y = 後半字典序的 sort
    for (int i = 0; i < m; i ++) c[i] = 0;
    for (int i = 0; i < n; i ++) c[x[i] = s[i]] ++;
    for (int i = 1; i < m; i ++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i --) sa[-- c[x[i]]] = i;
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < m; i ++) c[i] = 0;
        for (int i = 0; i < n; i ++) c[x[i]] ++;
        for (int i = 1; i < m; i ++) c[i] += c[i - 1];
        int p = 0;
        for (int i = n - k; i < n; i ++) y[p ++] = i;
        for (int i = 0; i < n; i ++) {
            if (sa[i] >= k) y[p ++] = sa[i] - k;
        }
        for (int i = n - 1; i >= 0; i --) sa[-- c[x[y[i]]]] = y[i];
        y[sa[0]] = p = 0;
        for (int i = 1; i < n; i ++) {
            int a = sa[i], b = sa[i - 1];
            if (x[a] == x[b] and a + k < n and b + k < n and x[a + k] == x[b + k]);
            else p ++;
            y[sa[i]] = p;
        }
        if (n == p + 1) break;
        swap(x, y);
        m = p + 1;
    }
}
void getlcp() {
    int n = s.size(), val = 0;
    for (int i = 0; i < n; i ++) rk[sa[i]] = i;
    for (int i = 0; i < n; i ++) {
        if (rk[i] == 0) lcp[rk[i]] = 0;
        else {
            if (val) -- val;
            int p = sa[rk[i] - 1];
            while (val + i < n and val + p < n and s[val + i] == s[val + p]) val ++;
            lcp[rk[i]] = val;
        }
    }
}