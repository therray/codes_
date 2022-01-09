// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> 
struct SegTree {
  int n;
  vector<T> tree;
  F op;
  T def;
  SegTree(int _n, F _op, T _def = T{}) : n(_n), op(_op), def(_def) {
    tree.resize((n << 1));
    for (int i = n - 1; i > 0; --i) {
      tree[i] = op(tree[(i << 1)], tree[(i << 1) | 1]);
    }
  }
  T get(int l, int r) {
    l += n;
    r += n + 1;
    T resl = def;
    T resr = def;
    while (l < r) {
      if (l & 1) {
        resl = op(resl, tree[l]);  
        l += 1;
      }
      if (r & 1) {
        r -= 1;
        resr = op(tree[r], resr);
      }
      l >>= 1;
      r >>= 1;
    }
    return op(resl, resr);
  }
  template<typename FF = function<void(T&)>> 
  void modify(int x, FF change) {
    x += n;
    change(tree[x]);
    while (x > 1) {
      int l = x;
      int r = x ^ 1;
      if (l > r) {
        swap(l, r);
      }
      tree[x >> 1] = op(tree[l], tree[r]);
      x >>= 1;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  SegTree<int> st(N, [&](int x, int y) {
    return max(x, y);
  });
  int Q;
  cin >> Q;
  while (Q--) {
    int L, R, X;
    cin >> L >> R >> X;
    if (X == -1) {
      st.modify(L, [&](int& x) {
        x += R;
      });
    } else {
      cout << st.get(L, R) << endl;
    }
  }
}