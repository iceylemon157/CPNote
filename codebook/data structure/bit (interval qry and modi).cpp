struct BIT {
    static const int mxN = 2e5 + 50;
    int n, bit[mxN], ibit[mxN];
    inline void init(int _n) {
        n = _n; for(int i = 0; i <= n; i ++) bit[i] = ibit[i] = 0;
    }
    inline int low(int x) { return x & -x; }
    inline void modi(int a, int b, int v) {
        b ++;
        for(int tv = a * v; a <= n; a += low(a)) bit[a] += v, ibit[a] += tv;
        for(int tv = b * v; b <= n; b += low(b)) bit[b] -= v, ibit[b] -= tv;
    }
    inline int qry(int x) {
        int ret = 0, tsum = 0, ttsum = 0;
        for(int tx = x; tx > 0; tx -= low(tx)) ret += (x + 1) * bit[tx] - ibit[tx];
        return ret;
    }
} bit;