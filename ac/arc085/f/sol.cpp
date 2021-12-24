#undef DEBUG 
// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

const int inf = int(1e7);
struct SegTree {
  vector<int> tree;
  int n;
  SegTree(int _n) : n(_n) { 
    tree.resize(n << 1, inf);
  }
  void modify(int p, int x) {
    p += n;
    tree[p] = min(tree[p], x);
    while (p > 1) {
      tree[p >> 1] = min(tree[p], tree[p ^ 1]);
      p >>= 1;
    }
  }
  int get(int l, int r) {
    l += n;
    r += n + 1;
    int res = inf;
    while (l < r) {
      if (l & 1) {
        res = min(res, tree[l]);
        ++l;
      }
      if (r & 1) {
        --r;        
        res = min(res, tree[r]);
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
  int N;
  cin >> N;
  vector<int> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }                 
  vector<int> pref(N + 1);
  for (int i = 0; i < N; ++i) {
    pref[i + 1] = pref[i] + B[i];
  }

  auto Ct = [&](int l, int r, int c) {
    assert(l >= 0 && l <= r && r < N);
    int x = pref[r + 1] - pref[l];
    return (c ? x : r - l + 1 - x);
  };
  
  int Q;
  cin >> Q;
  vector<int> L(Q), R(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> L[i] >> R[i];
    --L[i], --R[i];
  }
  vector<int> ord(Q);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) {
    return pair{R[x], L[x]} > pair{R[y], L[y]};
  });
  debug(ord);

  SegTree move_mx(N + 1);
  SegTree still_mx(N + 1);
  still_mx.modify(N, pref[N]);
  for (auto id : ord) {
    int l = L[id];
    int r = R[id];
    int best = min(move_mx.get(l, r + 1) - (l - pref[l]), still_mx.get(r + 1, N) - pref[r + 1] + Ct(l, r, 0));
    debug(l, r, best);
    move_mx.modify(l, best + (l - pref[l]));
    still_mx.modify(l, best + pref[l]);
  }
  
  int ans = N;
  for (int i = 0; i <= N; ++i) {
    debug(move_mx.get(i, i) + i - 2 * pref[i], still_mx.get(i, i));
    ans = min({ans, move_mx.get(i, i) - (i - pref[i]) + pref[i], still_mx.get(i, i)}); 
  }
  cout << ans << '\n';
}