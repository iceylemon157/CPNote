vector<int> poly_div(int N, vector<int> a) {
	vector<int> res(N << 1);
	if(N == 1) {
		res[0] = fp(a[0], Mod - 2);
		return res;
	}
	vector<int> b;
	b = poly_div(N >> 1, a);
	for(int i = N; i < sz(a); i ++) a[i] = 0;
	a.resize(N << 1);
	b.resize(N << 1);
	ntt.init(N << 1, 3, Mod);
	ntt.dft(a);
	ntt.dft(b);
	for(int i = 0; i < (N << 1); i ++) {
		res[i] = (2 - a[i] * b[i] % Mod + Mod) % Mod * b[i] % Mod;
	}
	ntt.idft(res);
	for(int i = N; i < (N << 1); i ++) res[i] = 0;
	return res;
}
