void init(int x, int fa = -1) {
    sz[x] = 1;
    int mx = 0;
    for (int i : vc[x]) {
        if (i == fa) continue;
        init(i, x);
        sz[x] += sz[i];
        if (sz[i] > mx) {
            mx = sz[i];
            mxson[x] = i;
        }
    }
}
void add(int x) {
    int t = val[x];
    sum[cnt[t]] -= t;
    sum[++ cnt[t]] += t;
    most = max(most, cnt[t]);
}
void sub(int x) {
    int t = val[x];
    sum[cnt[t] --] -= t;
    sum[cnt[t]] += val[x];
    if (sum[most] == 0) most --;
}
void upd(int x, int fa, int clear) {
    if (clear) sub(x);
    else add(x);
    for (int i : vc[x]) {
        if (i != fa) upd(i, x, clear);
    }
}
void dfs(int x, int fa = -1) {
    for (int i : vc[x]) {
        if (i == fa or i == mxson[x]) continue;
        dfs(i, x);
        upd(i, x, 1);
    }
    if (mxson[x]) dfs(mxson[x], x);
    for (int i : vc[x]) {
        if (i != fa and i != mxson[x]) {
            upd(i, x, 0);
        }
    }
    add(x);
    ans[x] = sum[most];
}
