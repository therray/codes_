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
  int N, X;
  long long Y;
  cin >> N >> X >> Y;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  
  vector<long long> dp(1 << N, (long long) 2e18);
  dp[0] = 0;
  for (int i = 0; i < (1 << N); ++i) {
    int pos = __builtin_popcount(i);
    int swaps = -1;
    for (int j = 0; j < N; ++j) {
      if ((i >> j) & 1) {
        continue;
      }
      swaps += 1;
      dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + 1LL * X * abs(A[j] - B[pos]) + Y * swaps);
    }
  }

  cout << dp.back() << '\n';
}