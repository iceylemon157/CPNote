struct segment {
    int m, k;
    int val(int x) {
        return m * x + k;
    }
} tr[maxn * 15];

struct LiChao {
    int tot = 0;
    int ls[maxn * 15], rs[maxn * 15];
    inline int newnode() {
        int x = ++ tot;
        tr[x].m = 0, tr[x].k = -inf;
        return x;
    }
    void add(segment seg, int &rt, int l = 1, int r = 1e9 + 50) {
        if(!rt) rt = newnode();
        if(l == r) {
            if(seg.val(l) > tr[rt].val(l)) tr[rt] = seg;
            return;
        }
        int md = (l + r) >> 1;
        if(seg.m < tr[rt].m) swap(seg, tr[rt]);
        if(seg.val(md) > tr[rt].val(md)) {
            swap(seg, tr[rt]);
            add(seg, ls[rt], l, md);
        }
        else add(seg, rs[rt], md + 1, r);
    }
    int qry(int v, int rt, int l = 1, int r = 1e9 + 50) {
        if(!rt) return -inf;
        if(l == r) return tr[rt].val(v);
        int md = (l + r) >> 1;
        int ret = tr[rt].val(v);
        if(v <= md) ret = max(ret, qry(v, ls[rt], l, md));
        else ret = max(ret, qry(v, rs[rt], md + 1, r));
        return ret;
    }
} LCT;