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
  vector<T> a;
  SegTree(int _n) : n(_n) {
    a.resize(n << 1);
  }

  template<typename... F> void modify(int x, F... M) {
    x += n;
    a[x].modify(M...);
    while (x > 1) {
      a[(x >> 1)] = a[x] + a[x ^ 1];
      x >>= 1;
    }
  }

  T get(int l, int r) {
    T res = {};
    l += n;
    r += n + 1;
    while (l < r) {
      if (l & 1) {
        res = res + a[l];
        ++l;
      }
      if (r & 1) {
        --r;
        res = res + a[r];
      }
      l >>= 1;
      r >>= 1;
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
}