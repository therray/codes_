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
  int N;
  long long W, L;
  cin >> N >> L >> W;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  A.push_back(L);
  long long l = 0;
  long long ans = 0;
  for (int i = 0; i <= N; ++i) {
    long long x = A[i];
    ans += (max(0LL, x - l) + (W - 1)) / W;
    l = x + W;
  }
  cout << ans << '\n';
}