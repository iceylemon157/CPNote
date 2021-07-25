struct DSU {
	const static int mxN = 2e5 + 50;
	int n, pa[mxN], sz[mxN];
	void init(int _n) {
		n = _n;
		for(int i = 1; i <= n; i ++) pa[i] = i, sz[i] = 1;
	}
	inline bool same(int a, int b) { return (get(a) == get(b)); }
	int get(int x) { return x == pa[x]? x : pa[x] = get(pa[x]); }
	inline void uni(int a, int b) {
		a = get(a), b = get(b);
		if(a == b) return;
		if(sz[a] > sz[b]) swap(a, b);
		pa[a] = b;
		sz[b] += sz[a];
	}
};
