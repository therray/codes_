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
  int N;
  cin >> N;     
  const int MAX = 50 * 49 / 2 + 1;
  vector<vector<array<int, 2>>> dp(MAX, vector<array<int, 2>>(MAX, {-1, -1}));
  dp[0][0] = {0, 0};
  for (int a = 1; a < N; ++a) {
    for (int i = MAX - 1; i >= 0; --i) {
      for (int j = MAX - 1; j >= 0; --j) {
        if (dp[i][j][0] != -1) {
          if (dp[i + a][j][0] == -1) dp[i + a][j] = {0, a};
          if (dp[i][j + a][0] == -1) dp[i][j + a] = {1, a};
        }
      }
    }
  }

  if (N % 3 == 2 || N < 6) {
    cout << "No\n";
    return 0;
  }
  int sum = N * (N - 1) / 2;
  assert(dp[sum / 3][sum / 3][0] != -1);
  cout << "Yes\n";
  array<int, 2> pos;
  pos.fill(sum / 3);
  vector<int> id(N, 2);
  while (pos[0] > 0 || pos[1] > 0) {
    auto[x, y] = dp[pos[0]][pos[1]];
    debug(pos[0], pos[1], x, y);
    id[y] = x;
    pos[x] -= y;
  }

  for (int i = 0; i < N; ++i) {
    cout << string(N - i - 1, "RBW"[id[N - i - 1]]) << '\n';
  }
}