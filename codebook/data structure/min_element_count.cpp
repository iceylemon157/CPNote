struct segt {
    // count the number of min element
    #define ls (idx << 1)
    #define rs (idx << 1 | 1)
    int n;
    vector<int> mn, cnt, tag;
    segt() {}
    segt(int x) {
        n = x;
        mn.resize(n << 2);
        cnt.resize(n << 2);
        tag.resize(n << 2);
    }
    void upd(int idx) {
        mn[idx] = min(mn[ls], mn[rs]);
        cnt[idx] = 0;
        if(mn[idx] == mn[ls]) cnt[idx] += cnt[ls];
        if(mn[idx] == mn[rs]) cnt[idx] += cnt[rs];
    }
    void down(int l, int r, int idx) {
        if(tag[idx] != 0) {
            tag[ls] += tag[idx];
            tag[rs] += tag[idx];
            mn[ls] += tag[idx];
            mn[rs] += tag[idx];
        }
    }
    pair<int, int> tqry(int a, int b, int l, int r, int idx) {
        if(a <= l and b >= r) {
            return make_pair(mn[idx], cnt[idx]);
        }
        down(l, r, idx);
        int md = (l + r) >> 1;
        pair<int, int> ret = {1e9, 1e9}, lp, rp;
        lp = rp = ret;
        if(a <= md) lp = tqry(a, b, l, md, ls);
        if(b > md) rp = tqry(a, b, md + 1, r, rs);
        if(lp.f == rp.f) ret = {lp.f, lp.s + rp.s};
        else ret = min(lp, rp);
        return ret;
    }
    void tmodi(int a, int b, int v, int l, int r, int idx) {
        if(a <= l and b >= r) {
            mn[idx] += v;
            tag[idx] += v;
            return;
        }
        down(l, r, idx);
        int md = (l + r) >> 1;
        if(a <= md) tmodi(a, b, v, l, md, ls);
        if(b > md) tmodi(a, b, v, md + 1, r, rs);
        upd(idx);
    }
    void modi(int a, int b, int v) {
        tmodi(a, b, v, 1, n, 1);
    }
    pair<int, int> qry(int a, int b) {
        return tqry(a, b, 1, n, 1);
    }
};
