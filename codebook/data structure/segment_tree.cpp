struct segt {
	#define ls (idx << 1)
	#define rs (idx << 1 | 1)
	static const int mxN = 2e5 + 50;
	int seg[mxN * 4], tag[mxN * 4];
	inline void upd(int idx) {
		seg[idx] = seg[ls] + seg[rs];
	}
	void build(int l = 1, int r = n, int idx = 1) {
		if(l == r) {
			// seg[idx] = a[l];
			return;
		}
		int md = (l + r) >> 1;
		build(l, md, ls);
		build(md + 1, r, rs);
		upd(idx);
	} 
	void down(int l, int r, int idx) {
		if(tag[idx] != 0) {
			int md = (l + r) >> 1;
			tag[ls] += tag[idx], tag[rs] += tag[idx];
			seg[ls] += tag[idx] * (md - l + 1);
			seg[rs] += tag[idx] * (r - md);
			tag[idx] = 0;
		}
	}
	int qry(int a, int b, int l = 1, int r = n, int idx = 1) {
		if(a <= l and b >= r) return seg[idx];
		down(l, r, idx);
		int md = (l + r) >> 1, ret = 0;
		if(a <= md) ret += qry(a, b, l, md, ls);
		if(b > md) ret += qry(a, b, md + 1, r, rs);
		return ret;
	}
	void modi(int a, int b, int v, int l = 1, int r = n, int idx = 1) {
		if(a <= l and b >= r) {
			seg[idx] += v * (r - l + 1);
			tag[idx] += v;
			return;
		}
		down(l, r, idx);
		int md = (l + r) >> 1;
		if(a <= md) modi(a, b, v, l, md, ls);
		if(b > md) modi(a, b, v, md + 1, r, rs);
		upd(idx);
	}
};
