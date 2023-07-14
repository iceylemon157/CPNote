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