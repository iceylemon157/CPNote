struct DSU {
    const static int mxN = 3e5 + 50;
    int n, cnt, pa[mxN], sz[mxN];
    vector<pair<int, int>> stk;
    void init(int _n) {
        n = cnt = _n;
        stk.clear();
        for(int i = 0; i <= n; i ++) pa[i] = i, sz[i] = 1;
    }
    inline bool same(int a, int b) { return (get(a) == get(b)); }
    inline int get(int x) {
        while(x != pa[x]) x = pa[x];
        return x;
    }
    inline void uni(int a, int b) {
        a = get(a), b = get(b);
        if(a == b) {
            stk.emplace_back(a, b);
            return;
        }
        if(sz[a] > sz[b]) swap(a, b);
        pa[a] = b;
        sz[b] += sz[a];
        stk.emplace_back(a, b);
        cnt --;
    }
    inline void del() {
        pair<int, int> p = stk.back(); stk.pop_back();
        int a = p.first, b = p.second;
        if(a == b) return;
        pa[a] = a;
        sz[b] -= sz[a];
        cnt ++;
    }
} dsu;
