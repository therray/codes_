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
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }

  vector<array<array<int, 2>, 2>> dp(N);
  for (int i = 0; i < N; ++i) {
    fill(dp[i].begin(), dp[i].end(), (long long) 1e17);
  }
  
  dp[0][0][0] = 0;
  dp[1][1][0] = A[0];
  for (int i = 0; i < N; ++i) {
    for (int first = 0; first < 2; ++first) {
      for (int used = 0; used < 2; ++used) {
        if (i + 1 < N) {
          dp[i + 1][first][1] = min(dp[i + 1][first][1], dp[i][first][used] + B[i]);
        }
        if (i + 2 < N) {
          dp[i + 2][first][used] = min(dp[i + 2][first][used], dp[i][first][used] + A[i + 1]);
        }
      }
    }
  }

  int ans = (long long) 1e17;
  for (int first = 0; first < 2; ++first) {
    for (int connected = 0; connected < 2; ++connected) {
      long long res = dp[n - 1][first][connected]; 
    }
  }

  cout << ans << '\n';
}
