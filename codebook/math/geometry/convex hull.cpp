vector<pdd> get_hull(vector<pdd> &v) {
    vector<pdd> up, down;
    sort(v.begin(), v.end());
    for(int i = 0; i < (int)v.size(); i ++) {
        while((int)up.size() >= 2 and cross(v[i] - up.back(), v[i] - up[up.size() - 2]) < 0) {
            up.pop_back();
        }
        while((int)down.size() >= 2 and cross(v[i] - down.back(), v[i] - down[down.size() - 2]) > 0) {
            down.pop_back();
        }
        up.emplace_back(v[i]);
        down.emplace_back(v[i]);
    }
    reverse(down.begin(), down.end());
    for(int i = down.size() - 2; i > 0; i --) up.emplace_back(down[i]);
    return up;
}