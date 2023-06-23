typedef pair<double, double> pdd;
#define x first
#define y second
const double eps = 1e-10;

pdd operator+(pdd a, pdd b) { return pdd(a.x + b.x, a.y + b.y); }
pdd operator-(pdd a, pdd b) { return pdd(a.x - b.x, a.y - b.y); }
pdd operator*(pdd a, double b) { return pdd(a.x * b, a.y * b); }
pdd operator/(pdd a, double b) { return pdd(a.x / b, a.y / b); }
inline double dot(pdd a, pdd b) { return a.x * b.x + a.y * b.y; }
inline double cross(pdd a, pdd b) { return a.x * b.y - a.y * b.x; }
inline double cross(pdd o, pdd a, pdd b) { return cross(a - o, b - o); }
inline double dist(pdd a, pdd b) { return sqrt(dot(a, b)); }
inline double dist(pdd a, pdd b, pdd c, bool issegment = false) {
    double d = cross(b - a, c - a) / dist(a, b);
    if(issegment) {
        double dt = dot(b - a, c - b);
        if(dt > 0) return dist(b, c);
        dt = dot(a - b, c - a);
        if(dt > 0) return dist(a, c);
    }
    return abs(d);
}
inline double dist2(pdd a, pdd b) { return dot(a, b); }
int sign(double a) {
    return (fabs(a) < eps? 0 : (a > 0? 1 : -1));
}
int ori(pdd a, pdd b, pdd c) {
    // vector ab to vector ac
    return sign(cross(b - a, c - a));
}
pdd p[maxn];
bool segment_intersection(pdd a, pdd b, pdd c, pdd d) {
    for(int i = 1; i <= 2; i ++) {
        double da = cross(b - a, c - a);
        double db = cross(b - a, d - a);
        if((da > 0.0 and db > 0.0) or (da < 0.0 and db < 0.0)) return false;
        if(da == 0.0 and db == 0.0) {
            if(max(a.x, b.x) < min(c.x, d.x) or max(a.y, b.y) < min(c.y, d.y)) return false;
        }
        swap(a, c);
        swap(b, d);
    }
    return true;
}
bool polar_cmp(pdd a, pdd b) {
    #define is_neg(k) (sign(k.s) < 0 or (sign(k.s) == 0 && sign(k.f) < 0))
    int A = is_neg(a), B = is_neg(b);
    if(A != B) return A < B;
    if(sign(cross(a, b)) == 0) return dist2(a) < dist2(b); // might be wrong
    return sign(cross(a, b)) > 0;
}
bool btw(pdd a, pdd b, pdd c) {
    // segment ab, check c in or not
    if(cross(a - c, b - c)) return 0;
    return sign(dot(a - c, b - c)) <= 0;
}