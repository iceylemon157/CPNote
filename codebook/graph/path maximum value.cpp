const int mxN = 2e5 + 50;
int up[mxN][20], mx[mxN][20], dep[mxN];

inline void lca_init(int N) {
    function<void(int, int)> dfs = [&](int x, int fa) {
        for(pii p : vc[x]) {
            int i = p.f;
            if(i == fa) continue;
            up[i][0] = x;
            mx[i][0] = p.s;
            dep[i] = dep[x] + 1;
            dfs(rt, i, x);
        }
    };
    for(int i = 1; i <= N; i ++) {
        if(!dep[i]) {
            dep[i] = 1;
            dfs(i, i, -1);
        }
    }
    for(int i = 1; i <= 18; i ++) {
        for(int i = 1; i <= N; i ++) {
            mx[j][i] = max(mx[j][i - 1], mx[up[j][i - 1]][i - 1]);
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
}

inline int lca(int a, int b) {
    int ans = 0;
    if(dep[a] < dep[b]) swap(a, b);
    int lg = log2(max(dep[a], dep[b]));
    for(int i = lg + 1; i >= 0; i --) {
        if(dep[up[a][i]] >= dep[b]) {
            ans = max(ans, mx[a][i]);
            a = up[a][i];
        }
    }
    if(a == b) return ans;
    lg = log2(max(dep[a], dep[b]));
    for(int i = lg; i >= 0; i --) {
        if(up[a][i] != up[b][i]) {
            ans = max({ans, mx[a][i], mx[b][i]});
            a = up[a][i], b = up[b][i];
        }
    }
    ans = max({ans, mx[a][0], mx[b][0]});
    return ans;
}