struct LinearBasis {
    static const int MAXL = 60;
    int a[MAXL + 1], sz = 0;
    inline void addVector(int p) {
        for(int i = MAXL; i >= 0; i --) {
            if(!(p >> i)) continue;
            if(!a[i]) {
                a[i] = p;
                sz ++;
                break;
            }
            p = p ^ a[i];
        }
    }
};