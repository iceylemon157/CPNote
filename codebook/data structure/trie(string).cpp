#include "bits/stdc++.h"
using namespace std;
struct trie {
	/*
		trie for string
	*/
	static const int mxN = 1e5 + 50;
	static const int mxC = 30;
	int tot = 1;
	int tr[mxN][mxC], cnt[mxN];
	inline void insert(string s) {
		for(int i = 0, idx = 1; i < (int)s.size(); i ++) {
			int c = s[i] - 'a';
			if(!tr[idx][c]) tr[idx][c] = ++ tot;
			cnt[idx] ++;
			idx = tr[idx][c];
		}
	}
	inline void del(string s) {
		for(int i = 0, idx = 1; i < (int)s.size(); i ++) {
			int c = s[i] - 'a';
			cnt[idx] --;
			idx = tr[idx][c];
		}
	}
	inline int query(string s) {
		// Query how many strings have prefix s
		int idx = 1;
		for(int i = 0; i < (int)s.size(); i ++) {
			int c = s[i] - 'a';
			idx = tr[idx][c];
		}
		return cnt[idx];
	}
} tree;