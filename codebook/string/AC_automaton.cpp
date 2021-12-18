struct AC_automaton {
    static const int mxN = 2e5 + 5, mxW = 26;
    int ch[mxN][mxW], fail[mxN], cnt[mxN], tot, dp[mxN], in[mxN];
    void init() {
        memset(ch, 0, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        memset(cnt, 0, sizeof(cnt));
        memset(dp, 0, sizeof(dp));
        tot = 0;
    }
    inline int insert(string s) {
        int id = 0;
        for(int i = 0; i < (int)s.size(); i ++) {
            if(!ch[id][s[i] - 'a']) ch[id][s[i] - 'a'] = ++ tot;
            id = ch[id][s[i] - 'a'];
        }
        cnt[id] ++;
        return id;
    }
    inline void build_fail() {
        // build AC after insert all strings
        queue<int> q;
        for(int i = 0; i < mxW; i ++) if(ch[0][i]) q.push(ch[0][i]);
        while(!q.empty()) {
            int id = q.front(); q.pop();
            for(int i = 0; i < mxW; i ++) {
                int &to = ch[id][i], tmp;
                if(ch[id][i]) {
                    q.push(to), tmp = fail[id];
                    while(tmp and !ch[tmp][i]) tmp = fail[tmp];
                    fail[to] = ch[tmp][i];
                    // fail[id] 是 id 的子字串
                    // cnt[id] += cnt[fail[id]];
                }
                else to = ch[fail[id]][i];
            }
            in[fail[id]] ++;
        }
    }
    inline void count(string &s) {
        int id = 0, ret = 0, tid;
        for(int i = 0; i < (int)s.size(); i ++) {
            while(id and !ch[id][s[i] - 'a']) id = fail[id];
            if(ch[id][s[i] - 'a']) id = ch[id][s[i] - 'a'];
            dp[id] ++;
            tid = id;
            while(tid) {
                // do something
                tid = fail[tid];
            }
        }
    }
    inline void topo() {
        queue<int> q;
        FFOR(i, 0, tot) if(!in[i]) q.push(i);
        while(!q.empty()) {
            int id = q.front(); q.pop();
            dp[fail[id]] += dp[id];
            in[fail[id]] --;
            if(!in[fail[id]]) q.push(fail[id]);
        }
    }
} AC;