struct sgb {
    /*
    support query: interval sum, interval max
    support modify: interval min(a_i, t)
    */
    #define ls (idx << 1)
    #define rs (idx << 1 | 1)
    static const int mxN = 4e5 + 50;
    int n;
    int seg[mxN], mx[mxN], smx[mxN], tag[mxN], mx_cnt[mxN];

    sgb(int _n): n(_n) {}

    inline void upd(int idx) {
        mx[idx] = max(mx[ls], mx[rs]);
        seg[idx] = seg[ls] + seg[rs];
        if(mx[ls] > mx[rs]) {
            mx_cnt[idx] = mx_cnt[ls];
            smx[idx] = max(smx[ls], mx[rs]);
        }
        else if(mx[ls] < mx[rs]) {
            mx_cnt[idx] = mx_cnt[rs];
            smx[idx] = max(mx[ls], smx[rs]);
        }
        else {
            mx_cnt[idx] = mx_cnt[ls] + mx_cnt[rs];
            smx[idx] = max(smx[ls], smx[rs]);
        }
    }

    void build(int l, int r, int idx = 1) {
        tag[idx] = -1;
        if(l == r) {
            seg[idx] = a[l];
            mx[idx] = a[l];
            mx_cnt[idx] = 1;
            return;
        }
        int md = (l + r) >> 1;
        build(l, md, ls);
        build(md + 1, r, rs);
        upd(idx);
    }

    inline void give_tag(int v, int idx) {
        if(v >= mx[idx]) return;
        tag[idx] = v;
        seg[idx] -= mx_cnt[idx] * (mx[idx] - v);
        mx[idx] = v;
    }

    inline bool tag_condition(int v, int idx) {
        if(v > smx[idx]) return 1;
        return 0;
    }

    inline void down(int idx) {
        if(tag[idx] == -1) return;
        int v = tag[idx];
        tag[idx] = -1;
        give_tag(v, ls);
        give_tag(v, rs);
    }

    void modi(int a, int b, int v, int l, int r, int idx = 1) {
        if(a <= l and b >= r) {
            if(tag_condition(v, idx)) {
                return give_tag(v, idx);
            }
        }
        if(l != r) down(idx);
        int md = (l + r) >> 1;
        if(a <= md) modi(a, b, v, l, md, ls);
        if(b > md) modi(a, b, v, md + 1, r, rs);
        upd(idx);
    }

    pii qry(int a, int b, int l, int r, int idx = 1) {
        if(a <= l and b >= r) {
            return {seg[idx], mx[idx]};
        }
        down(idx);
        int md = (l + r) >> 1;
        pii p = {0, 0};
        if(a <= md) p = qry(a, b, l, md, ls);
        if(b > md) {
            pii tp = qry(a, b, md + 1, r, rs);
            p.f += tp.f, p.s = max(p.s, tp.s);
        }
        return p;
    }
}