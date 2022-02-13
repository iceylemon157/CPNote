/*

dp[i] = min{dp[j] + a[i] * b[j]}

*/

struct seg {
    int m, k;
    seg(int x, int y) {
        m = x, k = y;
    }
    int val(const int x) {
        return m * x + k;
    }
};
deque<seg> dq;
bool check(seg &L1, seg &L2, seg L) {
    return (L.m - L2.m) * (L.k - L1.k) <= (L.m - L1.m) * (L.k - L2.k);
}
 
void solve() {
    int n;
    vector<int> a(n + 1), b(n + 1), dp(n + 1);
    dq.emplace_back(seg(-b[0], -dp[0]));
    for(int i = 1; i <= n; i ++) {
        while((int)dq.size() >= 2 and dq[0].val(a[i]) < dq[1].val(a[i])) {
            dq.pop_front();
        }
        dp[i] = -dq[0].val(a[i]);
        seg tmp = seg(-b[i], -dp[i]);
        while((int)dq.size() >= 2 and check(dq[dq.size() - 2], dq.back(), tmp)) {
            dq.pop_back();
        }
        dq.emplace_back(tmp);
    }
}