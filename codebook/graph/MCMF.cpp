struct Cost_Flow {
    static const int N = 3005;
    static const int inf = 1e18;
    struct edge {
        int to, cap, rev, cost;
        edge() {}
        edge(int _to, int _cap, int _rev, int _cost): 
            to(_to), cap(_cap), rev(_rev), cost(_cost){}
    };
    vector<edge> g[N];
    int n, s, t;
    void add(int a, int b, int val, int cost) {
        g[a].pb(edge(b, val, (int)g[b].size(), cost));
        g[b].pb(edge(a, 0, (int)g[a].size() - 1, -cost));
    }
    void init(int _n, int _s, int _t) {
        n = _n, s = _s, t = _t;
        for(int i = 0; i <= n; i ++) g[i].clear();
    }
    int dis[N], pa[N], pa_id[N];
    bitset<N> inQ;
    pair<int, int> flow() {
        int flow = 0LL, cost = 0LL;
        while(1) {
            for(int i = 0; i <= n; i ++) dis[i] = inf;
            inQ = 0;
            int inf = dis[1];
            dis[s] = 0LL;
            queue<int> q;
            q.push(s);
            while(!q.empty()) {
                int now = q.front(); q.pop();
                inQ[now] = 0;
                for(int id = 0; id < (int)g[now].size(); id ++) {
                    edge e = g[now][id];
                    if(e.cap > 0 and dis[e.to] > dis[now] + e.cost) {
                        dis[e.to] = dis[now] + e.cost;
                        pa[e.to] = now;
                        pa_id[e.to] = id;
                        if(!inQ[e.to]) q.push(e.to), inQ[e.to] = 1;
                    }
                }
            }
            if(dis[t] == inf) break;
            int tflow = inf;
            for(int i = t; i != s; i = pa[i]) {
                tflow = min(tflow, g[pa[i]][pa_id[i]].cap);
            }
            flow += tflow;
            cost += dis[t] * tflow;
            for(int i = t; i != s; i = pa[i]) {
                g[pa[i]][pa_id[i]].cap -= tflow;
                g[i][g[pa[i]][pa_id[i]].rev].cap += tflow;
            }
        }
        return make_pair(flow, cost);
    }
} flow;