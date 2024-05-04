struct DSU {
    // DSU for bipartite checking
    // Connetion of two Bipartite graph is a bipartite graph
    int n;
    vector<int> pa, sz, val;
    DSU(){}
    DSU(int x) {
        n = x;
        pa.resize(n + 1);
        sz.resize(n + 1);
        val.resize(n + 1);
        for (int i = 0; i <= n; i ++) {
            pa[i] = i;
            sz[i] = 1;
            val[i] = 0;
        }
    }
    int get(int x) {
        return (x == pa[x]? x : get(pa[x]));
    }
    int dist(int x) {
        return (x == pa[x]? val[x] : val[x] ^ dist(pa[x]));
    }
    bool uni(int a, int b) {
        // If after connect a, b the graph is bipartite: true
        int x = get(a), y = get(b);
        int dx = dist(a), dy = dist(b);
        if (x == y) return (dx != dy);
        if (sz[x] > sz[y]) swap(x, y), swap(dx, dy);
        sz[y] += sz[x];
        pa[x] = y;
        val[x] = dx ^ dy ^ 1;
        return 1;
    }
};
