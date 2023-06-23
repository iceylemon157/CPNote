int dis[maxn];
bitset<maxn> inq;
void SPFA(int s) {
	memset(dis, 0x3f, sizeof(dis));
	inq = 0;
	queue<int> q;
	q.push(s);
	dis[s] = 0; inq[s] = 1;
	while(!q.empty()) {
		int a = q.front();
		q.pop();
		inq[a] = 0;
		for(auto p : vc[a]) {
			int b = p.f, v = p.s;
			if(dis[b] > dis[a] + v) {
				dis[b] = dis[a] + v;
				if(!inq[b]) q.push(b);
			}
		}
	}
}
