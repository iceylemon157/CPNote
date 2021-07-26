typedef complex<double> point;
typedef complex<double> Vector;
#define x real()
#define y imag()

inline double dot(Vector a, Vector b) { return (conj(a) * b).x; }
inline double cross(Vector a, Vector b) { return (conj(a) * b).y; }
inline double cross(point a, point o, point b) { return cross(a - o, b - o); }
inline double dist(point a, point b) { return abs(a - b); }
inline double dist(point a, point b, point c, bool issegment = false) {
    double d = cross(b - a, c - a) / dist(a, b);
    if(issegment) {
        double dt = dot(b - a, c - b);
        if(dt > 0) return dist(b, c);
        dt = dot(a - b, c - a);
        if(dt > 0) return dist(a, c);
    }
    return abs(d);
}
template<class T>
istream& operator>> (istream& is, complex<T>& p) {
    T a, b;
    is >> a >> b;
    p = {a, b};
}

bool segment_intersection(point a, point b, point c, point d) {
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
