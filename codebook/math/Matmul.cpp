struct Mat {
	static const int N = 50;
	int r, c, m[N][N];
	Mat(){}
	Mat(int _r, int _c) { 
		r = _r; c = _c;
		memset(m, 0, sizeof(m));
	}
	int* operator[](int x) {
        return m[x];
    }
	Mat operator+(Mat a) {
		Mat ret(r, c);
		for(int i = 0; i < r; i ++) {
			for(int j = 0; j < c; j ++) {
				ret.m[i][j] = m[i][j] + a.m[i][j];
			}
		}
		return ret;
	}
	Mat operator*(Mat a) {
		assert(c == a.r);
		Mat ret(r, a.c);
		for(int i = 0; i < r; i ++) {
			for(int j = 0; j < a.c; j ++) {
				for(int k = 0; k < c; k ++) {
					ret.m[i][j] += m[i][k] * a.m[k][j];
				}
			}
		}
		return ret;
	}
	void print() {
		for(int i = 0; i < r; i ++) {
			for(int j = 0; j < c; j ++) {
				cout << m[i][j] << ' ';
			}
			cout << '\n';
		}
	}
};