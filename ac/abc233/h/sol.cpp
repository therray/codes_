// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

struct fenwick {
  vector<int> tree;
  int n;
  fenwick(int _n) : n(_n) {
    tree.resize(n + 1);
  }

  void modify(int x, int d) {
    x += 1;
    while (x <= n) {
      tree[x] += d;
      x += x & -x;
    }
  }

  int get(int x) {
    x += 1;
    int res = 0;
    while (x > 0) {
      res += tree[x];
      x = x & (x - 1);
    }
    return res;
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  const int MAX = int(1e5);
  for (int i = 0; i < N; ++i) {
    int _X, _Y;
    cin >> _X >> _Y;
    X[i] = _X - _Y + MAX;
    Y[i] = _X + _Y;
  }

  vector<int> ord(N);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) {
    return X[x] < X[y];
  });


  int Q;
  cin >> Q;
  vector<int> A(Q), B(Q), K(Q);
  for (int i = 0; i < Q; ++i) {
    int _A, _B;
    cin >> _A >> _B >> K[i];
    A[i]
  }
}