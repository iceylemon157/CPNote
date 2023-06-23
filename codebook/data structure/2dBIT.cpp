struct BIT2d {
    #define low(x) (x & -x)
    int n, m;
    vector<vector<int>> bit;
    BIT2d(){}
    BIT2d(int x, int y) {
        n = x, m = y;
        bit.resize(n + 1, vector<int>(m + 1));
    }
    int qry(int x, int y) {
        if(x <= 0 || y <= 0) return 0;
        int ret = 0;
        int ty = y;
        for(; x > 0; x -= low(x)) {
            for(y = ty; y > 0; y -= low(y)) {
                ret += bit[x][y];
            }
        }
        return ret;
    }
    int qry2(pii a, pii b) {
        a.f --, a.s --;
        return qry(b.f, b.s) - qry(b.f, a.s) - qry(a.f, b.s) + qry(a.f, a.s);
    }
    void modi(int x, int y, int v) {
        int ty = y;
        for(; x <= n; x += low(x)) {
            for(y = ty; y <= m; y += low(y)) {
                bit[x][y] += v;
            }
        }
    }
};