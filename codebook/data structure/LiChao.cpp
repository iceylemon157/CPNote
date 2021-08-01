struct segment {
    double m, k;
    double val(int x) {
        return m * x + k;
    }
} tr[maxn * 4];

struct LiChao {
    #define ls (idx << 1)
    #define rs (idx << 1 | 1)
    void add(segment seg, int l = 1, int r = 5e4, int idx = 1) {
        if(l == r) {
            if(seg.val(l) > tr[idx].val(l)) tr[idx] = seg;
            return;
        }
        int md = (l + r) >> 1;
        if(seg.m < tr[idx].m) swap(seg, tr[idx]);
        if(seg.val(md) > tr[idx].val(md)) {
            swap(seg, tr[idx]);
            add(seg, l, md, ls);
        }
        else add(seg, md + 1, r, rs);
    }
    double qry(int v, int l = 1, int r = 5e4, int idx = 1) {
        if(l == r) return tr[idx].val(v);
        int md = (l + r) >> 1;
        double ret = tr[idx].val(v);
        if(v <= md) ret = max(ret, qry(v, l, md, ls));
        else ret = max(ret, qry(v, md + 1, r, rs));
        return ret;
    }
} LCT;
