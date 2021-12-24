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
  string S;
  cin >> N >> S;
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    if (i == N - 1 || S[i] != S[i + 1]) {
      int p = i;
      while (p >= 0 && S[p] == S[i]) {
        --p;
      }
      int l = i - p;
      ans += 1LL * l * (l - 1) / 2;
    }
  }
  cout << ans << '\n';
}