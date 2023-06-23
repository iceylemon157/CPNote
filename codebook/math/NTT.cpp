const int mxN = 1 << 21;
struct NTT {
    // 用之前記得把陣列填充成二的冪次
    // rev: 下標反轉的陣列
    /*
        p=r*2^k+1
        p                     r       k       root
        998244353             119     23      3
        2013265921            15      27      31
        2061584302081         15      37      7
        2748779069441         5       39      3
        1945555039024054273   27      56      5
    */
    int kmod;
    int n, invn, rev[mxN];
    int g; // 原根 (root)
    int omega[mxN], iomega[mxN];
    int fp(int x, int p) {
        int ret = 1;
        while(p) {
            if(p & 1) ret = ret * x % kmod;
            x = x * x % kmod;
            p >>= 1;
        }
        return ret;
    }
    void init(int _n, int _g, int _mod) {
        n = _n;
        g = _g;
        kmod = _mod;
        invn = fp(n, kmod - 2);
        int x = fp(g, (kmod - 1) / n);
        omega[0] = 1;
        for(int i = 1; i < n; i ++) {
            omega[i] = 1ll * omega[i - 1] * x % kmod;
        }
        iomega[n - 1] = fp(omega[n - 1], kmod - 2);
        for(int i = n - 2; i >= 0; i --) {
            iomega[i] = 1ll * iomega[i + 1] * x % kmod;
        }
        int k = __lg(n);
        for(int i = 0; i < n; i ++) {
            int t = 0;
            for(int j = 0; j < k; j ++) {
                if((i & (1 << j))) t |= (1 << (k - j - 1));
            }
            rev[i] = t;
        }
    }
    void transform(vector<int> &a, int *xomega) {
        for(int i = 0; i < n; i ++) {
            if(i < rev[i]) swap(a[i], a[rev[i]]);
        }
        for(int len = 2; len <= n; len <<= 1) {
            int mid = len >> 1;
            int r = n / len;
            for(int j = 0; j < n; j += len) {
                for(int i = 0; i < mid; i ++) {
                    int t = 1ll * xomega[r * i] * a[j + mid + i] % kmod;
                    a[j + mid + i] = a[j + i] - t;
                    if(a[j + mid + i] < 0) a[j + mid + i] += kmod;
                    a[j + i] += t;
                    if(a[j + i] >= kmod) a[j + i] -= kmod;
                }
            }
        }
    }
    void dft(vector<int>& a) {
        transform(a, omega);
    }
    void idft(vector<int>& a) {
        transform(a, iomega);
        for(int i = 0; i < n; i ++) a[i] = 1ll * a[i] * invn % kmod;
    }
} ntt;
