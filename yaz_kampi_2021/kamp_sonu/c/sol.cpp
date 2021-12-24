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
  vector<int> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }

  vector<int> C(N);
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }

  const int INF = int(1e9);
  vector<array<int, 3>> dp(N + 1, {INF, INF, INF});
  int ans = INF;
  for (int i = 0; i < N; ++i) {
    dp[i][0] = C[i];
    for (int j = i - 1; j >= 0; --j) {
      for (int k = 1; k < 3; ++k) {
        if (S[j] < S[i]) {
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + C[i]);  
        }
      }
    }
    ans = min(ans, dp[i][2]);
  }
  cout << (ans == INF ? -1 : ans) << '\n';
}