struct Sparse_Table {
    int n;
    vector<int> lg;
    vector<vector<int>> ST;
    void RMQ_init(int _n, vector<int>& a) {
        n = _n;
        int k = __lg(n) + 1;
        lg.resize(n + 1);
        ST.resize(k + 1);
        ST[0] = a;
        for(int i = 1; i <= k; i ++) ST[i].resize(n + 1);
        for(int i = 2; i <= n; i ++) lg[i] = lg[i >> 1] + 1;
        for(int i = 1; i <= k; i ++) {
            for(int j = 1; j + (1 << i) - 1 <= n; j ++) {
                ST[i][j] = __gcd(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int get(int i, int j) {
        if(i == j) return ST[0][i];
        int t = lg[j - i + 1];
        return __gcd(ST[t][i], ST[t][j - (1 << t) + 1]);
    }
}