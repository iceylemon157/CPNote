int dis[maxn];
void BellmanFord(int s) {
	// vector<pii> vc[maxn]: (to, val)
	memset(dis, 0x3f, sizeof(dis));
	int inf = dis[0];
	dis[s] = 0;
	for(int t = 1; t <= n; t ++) {
		for(int i = 1; i <= n; i ++) {
			if(dis[i] == inf) continue;
			for(auto tp : vc[i]) {
				int j = tp.f, v = tp.s;
				dis[j] = min(dis[j], dis[i] + v);
			}
		}
	}
}