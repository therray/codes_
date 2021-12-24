// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int H, W, C, Q;
  cin >> H >> W >> C >> Q;
  vector<int> T(Q), N(Q), CL(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> T[i] >> N[i] >> CL[i];
    --CL[i], --T[i];
  }
  array<set<int>, 2> col;
  vector<long long> ans(C);       
  for (int i = Q - 1; i >= 0; --i) {
    if (col[T[i]].count(N[i])) {
      continue;
    }   
    ans[CL[i]] += (T[i] ? H : W) - int(col[T[i] ^ 1].size());
    col[T[i]].insert(N[i]);
  }

  for (int i = 0; i < C; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}