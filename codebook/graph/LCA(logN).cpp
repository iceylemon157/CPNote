const int mxN = 2e5;
int up[20][mxN], dep[mxN];

void lca_init(int rt) {
    dep[rt] = 1;
    function<void(int, int)> dfs = [&](int x, int fa) {
        for (int i : vc[x]) {
            if (i == fa) continue;
            up[0][i] = x;
            dep[i] = dep[x] + 1;
            dfs(i, x);
        }
    };
    dfs(rt, -1);
    for (int i = 1; i <= 18; i ++) {
        for (int j = 1; j <= n; j ++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 18; i >= 0; i --) {
        if (dep[up[i][a]] >= dep[b]) a = up[i][a];
    }
    if (a == b) return a;
    for (int i = 18; i >= 0; i --) {
        if (up[i][a] != up[i][b]) a = up[i][a], b = up[i][b];
    }
    return up[0][a];
}
