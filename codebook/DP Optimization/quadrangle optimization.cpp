
// dp(i) = min{dp(j) + w(i,j)}

struct segment {
    int i, l, r;
};
int n, dp[maxn];
deque<segment> dq;

inline int w(int l, int r) {
    // return a value
}

void solve() {
    dq.clear();
    dq.push_back({0, 1, n});
    for(int i = 1; i <= n; i ++) {
        // 把"過期"的區間pop掉
        while(dq.front().r < i) dq.pop_front();
        // 先得到dp[i]
        dp[i] = dp[dq.front().i] + w(dq.front().i, i);
        // 完全無法加入
        segment t = dq.back();
        if(dp[t.i] + w(t.i, n) < dp[i] + w(i, n)) {
            continue;
        }
        // 先移除掉會被i完全取代掉的區間
        while(!dq.empty()) {
            segment t = dq.back();
            if(i < t.l and dp[t.i] + w(t.i, t.l) > dp[i] + w(i, t.l)) {
                dq.pop_back();
            }
            else break;
        }
        // 特判全部被移掉的情形
        if(dq.empty()) {
            dq.push_back({i, i + 1, n});
            continue;
        }
        // 開始進行二分搜
        segment tmp = dq.back();
        int x = tmp.i, l = tmp.l, r = n, ans = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(dp[x] + w(x, mid) > dp[i] + w(i, mid)) {
                r = mid - 1;
                ans = min(ans, mid);
            }
            else l = mid + 1;
        }
        dq.pop_back();
        if(ans - 1 >= tmp.l) dq.push_back({tmp.i, tmp.l, ans - 1});
        dq.push_back({i, ans, n});
    }
}
