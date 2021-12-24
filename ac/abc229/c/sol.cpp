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
  int N, W;
  cin >> N >> W;
  vector<array<int, 2>> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i][0] >> A[i][1];
  }
  sort(A.rbegin(), A.rend());
  long long ans = 0;
  for (auto[d, a] : A) {
    int take = min(W, a);
    W -= take;
    ans += 1LL * d * take;
  }
  cout << ans << '\n';
}