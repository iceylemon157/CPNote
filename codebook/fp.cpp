int fp(int x, int p) {
	int ret = 1LL;
	while(p) {
		if(p & 1) ret = ret * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return ret;
}