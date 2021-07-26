typedef complex<double> point;
typedef complex<double> Vector;
#define x real()
#define y imag()

inline double dot(Vector a, Vector b) {	return (conj(a) * b).x; }
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
	return is;
} 
