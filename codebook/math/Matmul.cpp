struct Mat {
	static const int N = 55;
	int r, c, m[N][N];
	Mat(){}
	Mat(int _r, int _c) { 
		r = _r + 1; c = _c + 1;
		memset(m, 0, sizeof(m));
	}
	int* operator[](int x) {
        return m[x];
    }
	Mat operator+(Mat a) {
		Mat ret(r, c);
		for(int i = 1; i <= r; i ++) {
			for(int j = 1; j <= c; j ++) {
				ret[i][j] = m[i][j] + a[i][j];
			}
		}
		return ret;
	}
	Mat operator*(Mat a) {
		assert(c == a.r);
		Mat ret(r, a.c);
		for(int k = 1; k <= c; k ++) {
			for(int i = 1; i <= r; i ++) {
				for(int j = 1; j <= a.c; j ++) {
					ret.m[i][j] += m[i][k] * a.m[k][j];
				}
			}
		}
		return ret;
	}
	void print() {
		for(int i = 1; i <= r; i ++) {
			for(int j = 1; j <= c; j ++) {
				cout << m[i][j] << ' ';
			}
			cout << '\n';
		}
	}
};