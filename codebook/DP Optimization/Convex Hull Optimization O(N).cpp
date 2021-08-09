/*

dp[i] = min{dp[j] + a[i] * b[j]}

*/

double pt[maxn];
deque<int> dq;

struct segment {
    int m, k;
    int val(int x) { return m * x + k; }
} tr[maxn];

inline double get(int x, int y) {
    segment a = tr[x], b = tr[y];
    return 1.0 * (b.k - a.k) / (1.0 * (a.m - b.m));
}

bool upd(int x) {
    int y = dq.back();
    if((int)dq.size() == 1) {
        if(tr[y].val(0) < tr[x].val(0)) {
            dq.pop_back();
            return 1;
        }
    }
    else {
        if(get(y, x) <= pt[dq[dq.size() - 2]]) {
            dq.pop_back();
            return 1;
        }
    }
    return 0;
}

void solve() {
    int ans = 0;
    dq.pb(1);
    tr[1] = {-b[1], dp[1]};
    pt[1] = inf;
    FFOR(i, 2, n) {
        while(pt[dq[0]] < 1.0 * a[i]) dq.pop_front();
        dp[i] = -tr[dq.front()].val(a[i]);
        tr[i] = {-b[i], -dp[i]};
        pt[i] = inf;
        while(!dq.empty() and upd(i));
        if(!dq.empty()) pt[dq.back()] = get(dq.back(), i);
        dq.pb(i); 
    }
    cout << dp[n] << endl;
}
