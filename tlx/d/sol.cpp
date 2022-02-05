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
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> B(M);
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }

  auto Get = [&](vector<int> a) {
    debug(a);
    int n = int(a.size());
    array<int, 2> best = {-1, K + 1};
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      if (i - K >= 0) {
        sum -= a[i - K];
      }
      if (i >= K - 1) {
        debug(sum);
        best[0] = max(best[0], sum);
        best[1] = min(best[1], sum);
      }
    }
    return best;
  };

  auto a = Get(A);
  auto b = Get(B);
  debug(a, b);
  long long ans = 0;
  for (int i = 0; i < 2; ++i) {
    ans = max(ans, 1LL * a[i] * (K - b[i ^ 1]) + 1LL * (K - a[i]) * b[i ^ 1]);
  }
  cout << ans << '\n';
}