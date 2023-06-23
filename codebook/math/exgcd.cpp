pii exgcd(int a, int b) {
    if(b == 0) return {1, 0};
    pii p = exgcd(b, a % b);
    return {p.s, p.f - a / b * p.s};
}