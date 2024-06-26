struct Dinic {
    static const int N = 1e4 + 50;
    struct edge {
        int to, cap, rev;
        edge(int a, int b, int c) {
            to = a, cap = b, rev = c;
        }
    };
    int n, s, t;
    vector<edge> g[N];
    void init(int a, int b, int c) {
        n = a, s = b, t = c;
        for (int i = 0; i <= n; i ++) g[i].clear();
    }
    void add(int a, int b, int v) {
        g[a].push_back(edge(b, v, (int)g[b].size()));
        g[b].push_back(edge(a, 0, (int)g[a].size() - 1));
    }
    int iter[N], lvl[N];
    int dfs(int x, int flow) {
        if (x == t) return flow;
        for (int &it = iter[x]; it < (int)g[x].size(); it ++) {
            edge &e = g[x][it];
            if (e.cap > 0 and lvl[e.to] == lvl[x] + 1) {
                int tmp = dfs(e.to, min(flow, e.cap));
                if (tmp > 0) {
                    e.cap -= tmp;
                    g[e.to][e.rev].cap += tmp;
                    return tmp;
                }
            }
        }
        return 0;
    }
    void bfs() {
        memset(lvl, -1, sizeof(lvl));
        lvl[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int a = q.front(); q.pop();
            for (edge e : g[a]) {
                if (e.cap > 0 and lvl[e.to] == -1) {
                    q.push(e.to);
                    lvl[e.to] = lvl[a] + 1;
                }
            }
        }
    }
    int flow() {
        int ret = 0;
        while (1) {
            bfs();
            if (lvl[t] == -1) break;
            memset(iter, 0, sizeof(iter));
            int tmp;
            while ( (tmp = dfs(s, INF)) > 0) {
                ret += tmp;
            }
        }
        return ret;
    }
} flow;

