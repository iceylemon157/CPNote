struct Mat {
	static const int N = 55;
	int r, c, m[N][N];
	Mat(){}
	Mat(int _r, int _c) { 
		r = _r; c = _c;
		for(int i = 0; i < r; i ++) {
			for(int j = 0; j < c; j ++) {
				m[i][j] = 0;
			}
		}
	}
	int* operator[](int x) {
        return m[x];
    }
	Mat operator+(Mat a) {
		Mat ret(r, c);
		for(int i = 0; i < r; i ++) {
			for(int j = 0; j < c; j ++) {
				ret[i][j] = m[i][j] + a[i][j];
			}
		}
		return ret;
	}
	Mat operator*(Mat a) {
		assert(c == a.r);
		Mat ret(r, a.c);
		for(int k = 0; k < c; k ++) {
			for(int i = 0; i < r; i ++) {
				for(int j = 0; j < a.c; j ++) {
					ret[i][j] += m[i][k] * a[k][j];
				}
			}
		}
		return ret;
	}
	void mprint() {
		for(int i = 0; i < r; i ++) {
			for(int j = 0; j < c; j ++) {
				cout << m[i][j] << ' ';
			}
			cout << '\n';
		}
	}
};