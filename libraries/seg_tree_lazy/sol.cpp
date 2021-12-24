// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

template<typename T> struct SegTree {
  int n;
  vector<T> tree;
  T empty;
  SegTree(int _n) : n(_n) {
    tree.resize((n << 1) - 1);
  }   

  void pull(int v, int rv) {
    tree[v] = tree[v + 1] + tree[rv];
  }

  void push(int v, int l, int r) {
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    if (tree[v].tag != empty.tag) {
      tree[v + 1].modify(tree[v].tag, l, mid);
      tree[rv].modify(tree[v].tag, mid + 1, r);
    }
    tree[v].tag = empty.tag;
  }

  template<typename... F> void modify(int v, int l, int r, int ll, int rr, F... M) {
    if (l >= ll && rr >= r) {
      tree[v].modify(M..., l, r);
      return;
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, l, r);
    if (mid >= ll) {
      modify(v + 1, l, mid, ll, rr, M...);
    }
    if (mid < rr) {
       modify(rv, mid + 1, r, ll, rr, M...);
    }
    pull(v, rv);
  }

  T get(int v, int l, int r, int ll, int rr) {
    if (l >= ll && rr >= r) {
      return tree[v];
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, l, r);
    if (mid >= ll) {
      if (mid < rr) {
        return get(v + 1, l, mid, ll, rr) + get(rv, mid + 1, r, ll, rr);        
      } else {
        return get(v + 1, l, mid, ll, rr);
      }
    } else {
      return get(rv, mid + 1, r, ll, rr);  
    }
  }

  template<typename... F> void modify(int ll, int rr, F... M) {
    assert(ll <= rr && ll >= 0 && rr < n);
    modify(0, 0, n - 1, ll, rr, M...);
  }

  T get(int ll, int rr) {
    assert(ll <= rr && ll >= 0 && rr < n);
    return get(0, 0, n - 1, ll, rr);
  }
};

struct node {
  int mx = 0;
  int tag = 0;
  void modify(int x, int l, int r) {
    mx = max(x, mx);
    tag = max(tag, x);
  }

  node operator+(const node& ot) {
    node res;
    res.mx = max(mx, ot.mx);
    return res;
  }
};

using MaxSegTree = SegTree<node>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  MaxSegTree st(n);
  for (int i = 0; i < n; ++i) {
    st.modify(i, i, a[i]);
  }

  int q;
  cin >> q;
  while (q--) {
    int x, l, r;
    cin >> x >> l >> r;
    if (x == 0) {
      cout << st.get(l, r).mx << '\n';
    } else {
      int M;
      cin >> M;
      st.modify(l, r, M);
    }
  }
}