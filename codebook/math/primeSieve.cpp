const int mxN = 1e7 + 50;
int fac[mxN];
vector<int> prime;
void sieve(int mxN) {
    // This is a O(N) sieve
    for (int i = 2; i <= mxN; i ++) {
        if (!fac[i]) {
            fac[i] = i;
            prime.emplace_back(i);
        }
        for (int j : prime) {
            if(i * j > mxN) break;
            fac[i * j] = j;
            if(i % j == 0) break;
        }
    }
}
