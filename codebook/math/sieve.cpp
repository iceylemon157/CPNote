const int mxN = 1e7 + 50;
int mu[mxN], fac[mxN], phi[mxN];
vector<int> prime;
void sieve(int mxN) {
	// This is a O(N) sieve
	mu[1] = phi[1] = 1;
	for(int i = 2; i <= mxN; i ++) {
		if(!fac[i]) {
			fac[i] = i;
			mu[i] = -1;
			phi[i] = i - 1;
			prime.push_back(i);
		}
		for(int j : prime) {
			if(i * j > mxN) break;
			fac[i * j] = j;
			mu[i * j] = -mu[i];
			phi[i * j] = phi[i] * (j - 1);
			if(i % j == 0) {
				mu[i * j] = 0;
				phi[i * j] = phi[i] * j;
				break;
			}
		}
	}
}