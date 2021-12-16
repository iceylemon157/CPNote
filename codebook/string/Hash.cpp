int seed = 131;
vector<int> pw;
inline void pw_init(int n) {
	// n: length of maximum string
	for(int i = 0, tmp = 1; i < n; i ++) {
		pw.emplace_back(tmp);
		tmp = tmp * seed % mod;
	}
}
inline vector<int> Hash(string s) {
	// get prefix hash of string s
	int ret = 0;
	int n = s.size();
	vector<int> sum(n + 1);
	for(int i = 0; i < n; i ++) {
		sum[i + 1] = sum[i] + s[i] * pw[i];
		sum[i + 1] %= mod;
	}
	return sum;
}
inline bool get(vector<int> &sum, int l, int r, int tar) {
	// get the hash value of substr of s[L:R]
	// ret equal pw[l - 1] * hash value
	int ret = sum[r] - sum[l - 1];
	if(tar * pw[l - 1] % mod == ret) return 1;
	return 0;
}

