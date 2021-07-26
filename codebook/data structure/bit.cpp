struct BIT {
	static const int mxN = 2e5 + 50;
	#define low(x) (x & -x)
	int bit[mxN], n;
	inline void init(int _n) { n = _n; memset(bit, 0, sizeof(bit)); }
	inline int qry(int x) {
		int ret = 0;
		for(; x > 0; x -= low(x)) ret += bit[x];
		return ret;
	}
	inline void modi(int x, int v) {
		for(; x <= n; x += low(x)) bit[x] += v;
	}
};
