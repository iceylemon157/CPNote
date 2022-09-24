struct SW {
	static const int INF = 1e9;
	static const int N = 505;
	int n;
	vector<int> weight, vis, del;
	// del 第 i 個點有沒有被合併過
	// weight[i] 點集 A 到 i 的邊權和
	// adj[i][j] 點 i 到點 j 的權重和
	vector<vector<int>> adj;
	SW() {}
	SW(int _n) {
		n = _n;
		weight.resize(n);
		vis.resize(n);
		del.resize(n);
		adj.resize(n);
		for(int i = 0; i < n; i ++) {
			adj[i].resize(n);
			fill(all(adj[i]), 0);
		}
	}
	void add_edge(int x, int y, int w) {
		adj[x][y] += w;
		adj[y][x] += w;
	}
	void search(int &s, int &t) {
		fill(all(weight), 0);
		fill(all(vis), 0);
		s = t = -1;
		while(true) {
			int mx = -1, mx_id = 0;
			for(int i = 0; i < n; i ++) {
				if(!del[i] and !vis[i] and mx < weight[i]) {
					mx_id = i;
					mx = weight[i];
				}
			}
			if(mx == -1) break;
			vis[mx_id] = 1;
			s = t; t = mx_id;
			for(int i = 0; i < n; i ++) {
				if(!vis[i] and !del[i]) {
					weight[i] += adj[mx_id][i];
				}
			}
		}
	}
	int solve() {
		int ret = INF;
		for(int i = 0; i < n - 1; i ++) {
			int x, y;
			search(x, y);
			ret = min(ret, weight[y]);
			del[y] = 1;
			for(int j = 0; j < n; j ++) {
				adj[x][j] += adj[y][j];
				adj[j][x] += adj[y][j];
			}
		}
		return ret;
	}
} SW;