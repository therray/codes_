// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

const int inf = 0;
struct SegTree {
  int n;
  vector<int> mx;
  SegTree(int _n) : n(_n) {
    mx.resize((n << 1), -inf);
  }

  void modify(int i, int p) {
    assert(i >= 0 && i < n);
    mx[i += n] = p;
    while (i > 1) {
      mx[(i >> 1)] = max(mx[i], mx[i ^ 1]);
      i >>= 1;
    }
  }

  int get(int l, int r) {
    assert(l >= 0 && l <= r && r < n);
    l += n;
    r += n + 1;
    int res = -inf;
    while (l < r) {
      if (l & 1) {
        res = max(res, mx[l]);
        ++l;
      } 
      if (r & 1) {
        --r;
        res = max(res, mx[r]);
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
  int N, D;
  cin >> N >> D;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  map<int, vector<int>> pos;
  for (int i = 0; i < N; ++i) {
    pos[A[i]].push_back(i);
  }

  set<int> block;
  for (int i = 0; i < N; ++i) {
    block.insert(i);
  }
  SegTree st(N);
  vector<int> dp(N);
  for (auto[foo, a] : pos) {
    for (auto i : a) {
      auto it = block.lower_bound(i);
      while (it != block.begin() && *prev(it) + D >= i) {
        block.erase(prev(it));
        it = block.lower_bound(i);  
      }
      int lim = (it == block.begin() ? 0 : *prev(it) + 1);
      debug(i, block);
      dp[i] = st.get(lim, i) + 1;
    }
    for (auto i : a) {
      st.modify(i, dp[i]);
    }
  }
  debug(dp);
  cout << st.get(0, N - 1) << '\n';
}