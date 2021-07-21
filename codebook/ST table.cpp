int ST[maxn][25], lg[maxn];
void RMQ_init(int k) {
    FFOR(i, 2, n) lg[i] = lg[i >> 1] + 1;
    FOR(i, k) {
        for(int j = 1; j + (1 << i) - 1 <= n; j ++) {
            ST[j][i] = __gcd(ST[j][i - 1], ST[j + (1 << (i - 1))][i - 1]);
        }
    }
}
int get(int i, int j) {
    if(i == j) return ST[i][0];
    int t = lg[j - i + 1];
    return __gcd(ST[i][t], ST[j - (1 << t) + 1][t]);
}