struct E {
    int a, b, v;
} e[maxn];
int pa[maxn], sz[maxn];
void init_dsu(int n) { for(int i = 1; i <= n; i ++) pa[i] = i; }
int get(int x) { return pa[x] == x? x : pa[x] = get(pa[x]); }
void uni(int a, int b) {
    a = get(a), b = get(b);
    if(a == b) return;
    if(sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    pa[a] = b;
}
int kruskal(int n, int m) {
    init_dsu();
    sort(e + 1, e + m + 1, [](E a, E b) {
        return a.v < b.v;
    });
    int ret = 0, cnt = 0;
    for(int i = 1; i <= m; i ++) {
        int a = get(e[i].a), b = get(e[i].b);
        if(a == b) continue;
        uni(a, b);
        cnt ++;
        ret += e[i].v;
    }
    return (cnt == n - 1? ret : -1);
}
