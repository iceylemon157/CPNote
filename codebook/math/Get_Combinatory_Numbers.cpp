int J[maxn], inJ[maxn];
pii exgcd(int a, int b) {
    if(b == 0) return {1, 0};
    pii p = exgcd(b, a % b);
    return {p.s, p.f - a / b * p.s};
}

void init() {
    int N = 1e5;
    J[0] = J[1] = 1LL;
    FFOR(i, 2, N) J[i] = J[i - 1] * i % mod;
    inJ[N] = (exgcd(J[N], mod).f % mod + mod) % mod;
    for(int i = N - 1; i >= 1; i --) {
        inJ[i] = inJ[i + 1] * (i + 1) % mod;
    }
}

inline int C(int x, int y) {
    return J[x] * inJ[y] % mod * inJ[x - y] % mod;
}
