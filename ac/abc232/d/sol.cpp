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
  int H, W;
  cin >> H >> W;
  vector<string> C(H);
  for (int i = 0; i < H; ++i) {
    cin >> C[i];
  }

  int ans = -1;
  vector<vector<bool>> dp(H + 1, vector<bool>(W + 1));
  dp[0][0] = true;	
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (C[i][j] != '#' && dp[i][j]) {
        ans = max(ans, i + j);
        dp[i + 1][j] = true;
        dp[i][j + 1] = true;
      }
    }
  }

  cout << ans + 1 << '\n';
}