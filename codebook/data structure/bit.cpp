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
		int ret = 0, sum = 0;
		for(int i = 20; i >= 0; i --) {
			if(ret + (1 << i) <= n and sum + bit[ret + (1 << i)] < k) {
				ret += (1 << i);
				sum += bit[ret];
			}
		}
		for(int i = 0; i < 20; i ++) {
			if(sum + bit[ret + (1 << i)] >= k) {
				ret += (1 << i);
				break;
			}
		}
		return ret;
	}
};
