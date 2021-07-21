struct ODT {
	struct node {
		int l, r;
		mutable int v;
		node() {}
		node(int _l, int _r = -1, int _v = -1) {
			l = _l, r = _r, v = _v;
		}
		bool operator<(node a) const {
			return l < a.l;
		} 
	};
	#define IT set<node>::iterator
	int n;
	set<node> odt;
	inline void init() {
		odt.insert(node(1, n, 0));
	}
	inline IT split(int x) {
		IT it = odt.lower_bound(node(x));
		if(it != odt.end() and it->l == x) return it;
		it --;
		int l = it->l, r = it->r, v = it->v;
		odt.erase(it);
		odt.insert(node(l, x - 1, v));
		return odt.insert(node(x, r, v)).first;
	} 
	inline void assign(int l, int r, int v) {
		IT itr = split(r + 1), itl = split(l);
		odt.erase(itl, itr);
		odt.insert(node(l, r, v));
	}
	inline int qry(int l, int r) {
		IT itr = split(r + 1), itl = split(l);
		int ret = 0;
		for(IT it = itl; it != itr; it ++) {
			ret += (it->r - it->l + 1) * it->v;
		}
		return ret;
	}
} odt;
