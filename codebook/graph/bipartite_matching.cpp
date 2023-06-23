int match[maxn];
bitset<maxn> mvis;
bool hungary(int x) {
    for(int y : vc[x]) {
        if(mvis[y]) continue;
        mvis[y] = 1;
        if(!match[y] or hungary(match[y])) {
            match[y] = x;
            return 1;
        }
    }
    return 0;
}
inline int bipartite_matching() {
    // bipartite left-side n point
    int ret = 0;
    for(int i = 1; i <= n; i ++) {
        mvis = 0;
        ret += hungary(i);
    }
    return ret;
}