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
  string S;
  cin >> N >> S;
  int p = 0;
  while (p < N - 1 && S[p] == S[p + 1]) {
    ++p;
  }

  int ep = N - 1;
  while (ep >= 0 && S[ep] == S[0]) {
    --ep;
  }

  long long ans = 0;
  if (int(set<int>(S.begin(), S.end())) == 1) {
    ans = 1LL * N * (N + 1);
  }

  p += 1;
  long long ans = 1LL * p * (p + 1) / 2;
  ans += 1LL * p * (n - p);
  cout << ans % 998244353 << '\n'; 
}