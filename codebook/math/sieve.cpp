vector<int> prime;
int mu[maxn], fac[maxn];
void sieve(int mxN) {
	// This is a O(N) sieve
	mu[1] = 1;
	for(int i = 2; i <= mxN; i ++) {
		if(!fac[i]) {
			fac[i] = i;
			mu[i] = -1;
			prime.push_back(i);
		}
		for(int j : prime) {
			if(i * j > mxN) break;
			fac[i * j] = j;
			mu[i * j] = -mu[i];
			if(i % j == 0) {
				mu[i * j] = 0;
				break;
			}
		}
	}
}