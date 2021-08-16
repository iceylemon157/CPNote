#include "bits/stdc++.h"
#define int long long
#define ll long long
#define f first
#define s second
#define endl '\n'
#define INF 0x3f3f3f3f
#define mod 1000000007
#define Mod 998244353
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define mem(x, a) memset(x, a, sizeof(x))
#define FFOR(i, a, b) for(int i = a; i <= b; i ++)
#define FOR(i, n) FFOR(i, 1, n)
#define loli ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;
const int maxn = 1e6 + 50;
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.f >> a.s;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.f << ", " << a.s << ')';
}
namespace io {
    const int SIZE = 1e7 + 10;
    char inbuff[SIZE];
    char *l, *r;
    inline void init() {
        l = inbuff;
        r = inbuff + fread(inbuff, 1, SIZE, stdin);
    }
    inline char gc() {
        if (l == r) init();
        return (l != r) ? *(l++) : EOF;
    }
    void R(int &x) {
        x = 0; char ch = gc();
        while(!isdigit(ch)) ch = gc();
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
    }
} using io::R;

void solve() {
	
}

void input() {
	
}

signed main(){
	loli;
	#ifndef ONLINE_JUDGE
	freopen("C:/useless stuff/input.txt", "r", stdin);
	freopen("C:/useless stuff/output.txt", "w", stdout);
	#endif
	int tt = 1;
	// cin >> tt;
	while(tt --) {
		input();
		solve();
	}
}