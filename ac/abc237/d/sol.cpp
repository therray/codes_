// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int H, W;
  cin >> H >> W;
  vector<vector<int>> ans(W, vector<int>(H));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      int X;
      cin >> X;
      ans[j][i] = X;
    }
  }
  
  for (auto r : ans) {
    for (auto e : r) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}