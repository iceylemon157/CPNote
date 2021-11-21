struct trie {
    /*
        01trie
        support: 
        * add/del binary
        * global xor
        * global maximum xor with x
    */
    static const int mxN = 2e5 + 50;
    int tr[mxN][2], cnt[mxN];
    int tot = 1, totx = 0;
    // tot: total node, totx: global xor
    inline void insert(int x) {
        // insert a binary
        int idx = 1;
        for(int i = 30; i >= 0; i --) {
            int p = (x >> i) & 1;
            p ^= ((totx >> i) & 1);
            if(!tr[idx][p]) tr[idx][p] = ++ tot;
            idx = tr[idx][p];
        }
        cnt[idx] ++;
    }
    inline void del(int x) {
        // delete a binary
        int idx = 1;
        for(int i = 30; i >= 0; i --) {
            int p = (x >> i) & 1;
            idx = tr[idx][p];
        }
        cnt[idx] --;
    }
    inline void XOR(int x) {
        // global xor
        totx ^= x;
    }
    inline int query(int x) {
        // maximum xor with x
        int idx = 1, ret = 0;
        for(int i = 30; i >= 0; i --) {
            int p = (x >> i) & 1;
            p ^= ((totx >> i) & 1);
            if(tr[idx][p ^ 1]) {
                ret += (1LL << i);
                idx = tr[idx][p ^ 1];
            }
            else idx = tr[idx][p];
        }
        return ret;
    }
} tree;
