struct Mat {
	int n, m;
    vector<vector<int>> mat;
	Mat() {}
	Mat(int r, int c) { 
        n = r, m = c;
        mat = vector<vector<int>>(n, vector<int>(m));
	}
	int* operator [] (int x) {
        return &mat[x][0];
    }
	Mat operator + (Mat a) {
		Mat ret(n, m);
		for(int i = 0; i < n; i ++) {
			for(int j = 0; j < m; j ++) {
				ret[i][j] = mat[i][j] + a[i][j];
			}
		}
		return ret;
	}
	Mat operator * (Mat a) {
		assert(m == a.n);
		Mat ret(n, a.m);
		for(int k = 0; k < m; k ++) {
			for(int i = 0; i < n; i ++) {
				for(int j = 0; j < a.m; j ++) {
					ret[i][j] += mat[i][k] * a[k][j];
				}
			}
		}
		return ret;
	}
	void print() {
		for(int i = 0; i < n; i ++) {
			for(int j = 0; j < m; j ++) {
				cout << mat[i][j] << ' ';
			}
			cout << '\n';
		}
	}
};
