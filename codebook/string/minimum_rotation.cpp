string Minimum_Rotation(string a) {
    int n = a.size();
    a = a + a;
    int l = 0, r = 1;
    while (l < n and r < n) {
        int cnt = 0;
        while (a[l + cnt] == a[r + cnt]) {
            cnt ++;
        }
        if (a[l + cnt] > a[r + cnt]) {
            l += cnt + 1;
        }
        else r += cnt + 1;
        if (l == r) r ++;
    }
    return a.substr(min(l, r), n);
}