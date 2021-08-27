void gauss(vector<vector<double>> &v) {
    // 大小為 n * m 的矩陣, 採用 0-base
    // 解線性方程組用
    const double eps = 1e-9;
    if(v.empty()) return;
    int n = v.size(), m = v[0].size();
    int line = 0;
    for(int i = 0; i < m; i ++) {
        int p = -1;
        for(int j = line; j < n; j ++) {
            if(fabs(v[j][i]) < eps) continue;
            if(p == -1 or fabs(v[j][i]) > fabs(v[p][i])) {
                p = j;
            }
        }
        if(p == -1) continue;
        for(int j = 0; j < m; j ++) {
            swap(v[line][j], v[p][j]);
        }
        double tmp = v[line][i];
        for(int j = 0; j < m; j ++) {
            v[line][j] /= tmp;
        }
        for(int j = 0; j < n; j ++) {
            if(j == line) continue;
            double t = v[j][i] / v[line][i];
            for(int k = 0; k < m; k ++) {
                v[j][k] -= t * v[line][k];
            }
        }
        line ++;
    }
}
