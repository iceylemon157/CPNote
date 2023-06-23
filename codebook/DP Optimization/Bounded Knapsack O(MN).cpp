int Count[maxn], v[maxn], w[maxn];
// Count[i] : numbers of stuff i
// v[i] : value of stuff i
// w[i] : weight of stuff i
int dq[maxn], id[maxn], knap[maxn];
void Bounded_Knap(int N, int W) {
    for(int i = 1; i <= N; i ++) {
        int mx = min(Count[i], W / w[i]);
        for(int rem = 0; rem < w[i]; rem ++) {
            int l = 0, r = 0;
            for(int div = 0; div * w[i] + rem <= W; div ++) {
                int j = div * w[i] + rem;
                int val = knap[j] - div * v[i];
                while(l < r and dq[r - 1] <= val) r --;
                id[r] = div;
                dq[r ++] = val;
                knap[j] = dq[l] + div * v[i];
                if(id[l] <= div - mx) l ++;
            }
        }
    }
}

/*
dp[j] = max{dp[j - k * w[i]] + k * v[i]} k in [0, a[i]]

consider j = div * w[i] + rem
dp[j] = max{dp[(div - k) * w[i] + rem] + k * v[i]} k in [0, a[i]]

substitute k to div - k
dp[j] = max{dp[k * w[i] + rem] - k * v[i]} + div * v[i] 
dp[j] = max{dp[k * w[i] + rem] - k * v[i]} + div * v[i]
k in [div - a[i], div]
*/