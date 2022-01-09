// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

template<typename T> struct fenwick {
  int n;
  vector<T> tree;
  fenwick(int _n) : n(_n) {
    tree.resize(n + 1);
  }
  void add(int x, T d) {
    x += 1;
    while (x <= n) {
      tree[x] += d;
      x += x & -x;
    }
  }
  T get(int x) {
    x += 1;
    T res{};
    while (x > 0) {
      res += tree[x];
      x = x & (x - 1);
    }
    return res;
  }
};

template<typename T, typename F = function<T(const T&, const T&)>> 
struct SparseTable {
  int n;
  vector<vector<T>> table;
  F op;
  SparseTable(vector<T> a, F _op) : op(_op) {
    n = int(a.size());
    int lg = __lg(n) + 1;
    table.resize(lg);
    table[0] = a;
    for (int j = 1; j < lg; ++j) {
      int s = n - (1 << j) + 1;
      table[j].resize(s);
      for (int i = 0; i < int(table[j].size()); ++i) {
        table[j][i] = op(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]); 
      } 
    }
  }
  T get(int l, int r) {
    assert(l >= 0 && r < n && l <= r);
    int s = __lg(r - l + 1);
    return op(table[s][l], table[s][r - (1 << s) + 1]);
  }
};



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  } 
  
  SparseTable<int> st(A, [&](int x, int y) {
    return min(x, y);
  });
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) {
      cout << i << ' ' << j << ' ' << st.get(i, j) << '\n';
    } 
  }
}