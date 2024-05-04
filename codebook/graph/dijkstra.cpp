priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> vc[maxn];
int dis[maxn];
void dij(int st) {
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        int a = pq.top(); pq.pop();
        if (dis[a.s] <= a.f) continue;
        for (pii i : vc[a.s]) {
            if (i.s + a.f < dis[i.f]) {
                dis[i.f] = i.s + a.f;
                pq.push({dis[i.f], i.s});
            }
        }
    }
}
