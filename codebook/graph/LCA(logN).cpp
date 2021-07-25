const int mxN = 2e5;
int up[mxN][20], dep[mxN];

void lca_init(int rt) {
	dep[rt] = 1;
	function<void(int, int)> dfs = [&](int x, int fa) {
		for(int i : vc[x]) {
			if(i == fa) continue;
			up[i][0] = x;
			dep[i] = dep[x] + 1;
			dfs(i, x);
		}
	};
	dfs(rt, -1);
	for(int i = 1; i <= 18; i ++) {
		for(int j = 1; j <= n; j ++) {
			up[j][i] = up[up[j][i - 1]][i - 1];
		}
	}
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 18; i >= 0; i --) {
		if(dep[up[a][i]] >= dep[b]) a = up[a][i];
	}
	if(a == b) return a;
	for(int i = 18; i >= 0; i --) {
		if(up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
	}
	return up[a][0];
}
