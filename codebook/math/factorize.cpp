mt19937 ran(time(nullptr));

inline int mul(int a, int b, int m) {
    int ret = (__int128)a * b % m;
    return ret;
}

inline int fp(int x, int p, int m) {
    int ret = 1;
    while(p) {
        if(p & 1) ret = mul(ret, x, m);
        x = mul(x, x, m);
        p >>= 1;
    }
    return ret;
}

bool Miller_Rabin(int n) {
    if (n <= 3 or ((n % 6) & 3) != 1) return (n | 1) == 3;
    const int tst[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    int r = __builtin_ctzll((int64_t)(n - 1));
    int d = n >> r;
    for(auto &p : tst) {
        if(p % n) {
            int x = fp(p % n, d, n), i = r;
            while(x != 1 && x != n - 1 && i--) x = mul(x, x, n);
            if(i != r && x != n - 1) return false;
        }
    }
    return true;
}

int rho(int n) {
    int c = 1;
    auto f = [&](int x) { return mul(x, x, n) + c; };
    int x = 0, y = 0, p = 2, q, t = 0;
    while (t ++ % 128 or __gcd(p, n) == 1) {
        if (x == y) c = ran() % (n - 1) + 1, y = f(x = 2);
        if ((q = mul(p, x > y ? x - y : y - x, n))) p = q;
        x = f(x); y = f(f(y));
    }
    return __gcd(p, n);
}

void factor(int n, vector<int> &ans) {
    if(n == 1) return;
    if((n & 1) ^ 1) {
        ans.eb(2);
        factor(n >> 1, ans);
        return;
    }
    if(Miller_Rabin(n)) {
        ans.eb(n);
        return;
    }
    int x = rho(n);
    factor(x, ans);
    factor(n / x, ans);
}