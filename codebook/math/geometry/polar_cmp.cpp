bool polar_cmp(pdd a, pdd b) {
    #define is_neg(k) (sign(k.s) < 0 or (sign(k.s) == 0 && sign(k.f) < 0))
    int A = is_neg(a), B = is_neg(b);
    if(A != B) return A < B;
    if(sign(cross(a, b)) == 0) return dist2(a) < dist2(b);
    return sign(cross(a, b)) > 0;
}