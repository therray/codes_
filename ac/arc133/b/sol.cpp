// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct fenwick {
  vector<int> mx;
  int n;
  fenwick(int _n) : n(_n) {
    mx.resize(n + 1, 0);
  }

  int get(int x) {
    x += 1;
    int res = 0;
    while (x > 0) {
      res = max(res, mx[x]);
      x ^= x & -x;
    }
    return res;
  }
  
  void modify(int x, int v) {
    x += 1;
    while (x <= n) {
      mx[x] = max(mx[x], v);
      x += x & -x;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }  
  vector<int> Q(N);
  vector<int> pos(N + 1);
  for (int i = 0; i < N; ++i) {
    cin >> Q[i];
    pos[Q[i]] = i;
  }

  vector<int> val(N);
  fenwick bit(N);
  for (int i = 0; i < N; ++i) {
    for (int j = P[i]; j <= N; j += P[i]) {
      int p = pos[j];
      val[p] = max(val[p], (p == 0 ? 0 : bit.get(p - 1)) + 1);  
    }
    for (int j = P[i]; j <= N; j += P[i]) {
      int p = pos[j];
      bit.modify(p, val[p]);
    }
  }
  cout << bit.get(N - 1) << '\n';
}