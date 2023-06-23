bool inverse_matrix(vector<vector<int>>& a, vector<vector<int>>& ret) {
    // 大小為 n * n 的矩陣, 採用 0-base
    // 解反矩陣用
    // No Solution returns 0, else 1

    auto fp = [](int x, int p, int mod) {
        // get inverse
        int ret = 1;
        while(p) {
            if(p & 1) ret = ret * x % mod;
            x = x * x % mod;
            p >>= 1;
        }
        return ret;
    };

    if(a.empty()) return 1;
    int n = a.size(), m = 2 * n;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            v[i][j] = a[i][j];
        }
        v[i][i + n] = 1;
    }
    int line = 0;
    for(int i = 0; i < n; i ++) {
        int p = -1;
        for(int j = i; j < n; j ++) {
            if(v[j][i] == 0) continue;
            if(p == -1 or abs(v[j][i]) > abs(v[p][i])) {
                p = j;
            }
        }
        if(p == -1) return 0;
        for(int j = 0; j < m; j ++) {
            swap(v[line][j], v[p][j]);
        }
        int tmp = v[line][i];
        for(int j = 0; j < m; j ++) {
            v[line][j] *= fp(tmp, mod - 2, mod);
            v[line][j] %= mod;
        }
        for(int j = 0; j < n; j ++) {
            if(j == i) continue;
            int t = v[j][i] * fp(v[i][i], mod - 2, mod) % mod;
            for(int k = 0; k < m; k ++) {
                v[j][k] -= t * v[i][k] % mod;
                if(v[j][k] < 0) v[j][k] += mod;
            }
        }
        line ++;
    }
    ret.resize(n, vector<int>(n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            ret[i][j] = v[i][j + n];
        }
    }
    return 1;
}