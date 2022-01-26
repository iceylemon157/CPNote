const int mxN = 2e5 + 50;
// vc 原樹, cd cd樹
vector<int> vc[mxN], cd[mxN];
bitset<mxN> del;
int pa[mxN], sz[mxN];

void get_sz(int x, int fa = -1) {
    sz[x] = 1;
    for(int v : vc[x]) {
        if(v == fa or del[v]) continue;
        get_sz(v, x);
        sz[x] += sz[v];
    }
}

int get_centroid(int x, int n, int fa = -1) {
    for(int v : vc[x]) {
        if(v == fa or del[v]) continue;
        if(sz[v] > n / 2) return get_centroid(v, n, x);
    }
    return x;
}

int build_cd(int x) {
    get_sz(x);
    int cen = get_centroid(x, sz[x]);
    del[cen] = 1;
    for(int v : vc[cen]) {
        // do something
    }
    for(int v : vc[cen]) {
        if(del[v]) continue;
        int t = build_cd(v);
        pa[v] = cen;
        cd[cen].emplace_back(v);
    }
    return cen;
}