struct BIT {
	static const int mxN = 2e5 + 50;
	#define low(x) (x & -x)
	int bit[mxN], n;
	inline void init(int _n) { n = _n; memset(bit, 0, sizeof(bit)); }
	inline int qry(int x) {
		if(!x) return 0;
		int ret = 0;
		for(; x > 0; x -= low(x)) ret += bit[x];
		return ret;
	}
	inline void modi(int x, int v) {
		if(!x) return;
		for(; x <= n; x += low(x)) bit[x] += v;
	}
	inline int kth(int k) {
		int ret = 0;
		for(int i = 1 << 20; i > 0; i >>= 1) {
			if(ret + i <= n and bit[ret + i] < k) {
				k -= bit[ret += i];
			}
		}
		return ret + 1;
	}
};
