#include "iostream"
#include "iomanip"
#include "cstdio"
#include "cmath"
#include "cstring"
#include "algorithm"
#include "vector"
#include "map"
#include "set"
#include "bitset"
#include "queue"
#include "stack"
#include "cassert"
#include "functional"
#include "ctime"
#include "random"
#define int long long
#define ll long long
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x, a) memset(x, a, sizeof(x))
#define print(v) for(auto FBK : v) cout << FBK << ' '; cout << '\n';
#define discrete(v) sort(all(v)); v.resize(unique(all(v)) - v.begin());
#define FFOR(i, a, b) for(int i = a; i <= b; i ++)
#define FOR(i, n) FFOR(i, 1, n)
#define Fubuki_is_my_waifu ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;
const int mod = 1e9 + 7;
const int Mod = 998244353;
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
    void R(char &x) {
        char ch = gc();
        while(ch < 33 or ch > 128) ch = gc();
        x = ch;
    }
    void R(int &x) {
        bool neg = 0;
        x = 0; char ch = gc();
        while(!isdigit(ch)) {
            if(ch == '-') neg = 1;
            ch = gc();
        }
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
        if(neg) x = -x;
    }
} using io::R;

void solve() {
    
}

void init() {
    
}

signed main() {
    Fubuki_is_my_waifu;
    #ifndef ONLINE_JUDGE
    freopen("C:/useless stuff/input.txt", "r", stdin);
    freopen("C:/useless stuff/output.txt", "w", stdout);
    #endif
    int tt = 1;
    // cin >> tt;
    // R(tt);
    while(tt --) {
        init();
        solve();
    }
}