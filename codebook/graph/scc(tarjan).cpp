int scc[maxn], low[maxn], dep[maxn], tcnt, sccid;
bitset<maxn> inst;
vector<int> st;
void tarjan(int x) {
    low[x] = dep[x] = tcnt ++;
    inst[x] = 1;
    st.pb(x);
    for(int i : vc[x]) {
        if(!dep[i]) {
            tarjan(i);
            low[x] = min(low[x], low[i]);
        }
        else if(inst[i]) low[x] = min(low[x], dep[i]);
    }
    if(low[x] == dep[x]) {
        sccid ++;
        while(1) {
            int t = st.back(); st.pop_back();
            scc[t] = sccid;
            inst[t] = 0;
            if(t == x) return;
        }
    }
}
