void print(vector<vector<double>> &v) {
    for(auto i : v) {
        for(auto j : i) cout << j << " ";
        cout << "\n";
    }
    cout << endl;
}

// 用row
int id[maxn]; // 某些行可能全為0，要先做後面，故需要計順序
bool inverse_matrix(vector<vector<double>> &v) {
    // 大小為 n * 2n 的矩陣, 採用 0-base
    // 解反矩陣用
    // No Solution returns 0, else 1
    const double eps = 1e-9;
    if(v.empty()) return 1;
    int n = v.size(), m = v[0].size();
    for(int i = 0; i < n; i ++) {
        int p = -1;
        for(int j = i; j < n; j ++) {
            if(fabs(v[j][i]) < eps) continue;
            if(p == -1 or fabs(v[j][i]) > fabs(v[p][i])) {
                p = j;
            }
        }
        if(p == -1) return 0;
        for(int j = 0; j < m; j ++) {
            swap(v[line][j], v[p][j]);
        }
        double tmp = v[line][i];
        for(int j = 0; j < m; j ++) {
            v[line][j] /= tmp;
        }
        for(int j = 0; j < n; j ++) {
            if(j == i) continue;
            double t = v[j][i] / v[i][i];
            for(int k = 0; k < m; k ++) {
                v[j][k] -= t * v[i][k];
            }
        }
    }
    return 1;
}
