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
  string S;
  cin >> S;
  int N = int(S.size());
  int p = 0;
  while (p < N && S[p] == 'a') {
    ++p;
  }
  int r = N - 1;
  while (r >= 0 && S[r] == 'a') {
    --r;
  }
  debug(p, r);

  while (N - r - 1 > p) {
    S.pop_back();
    --N;
  }
  debug(S);

  bool ok = true;
  for (int i = 0; i < N; ++i) {
    ok &= (S[i] == S[N - i - 1]);
  }
  cout << (ok ? "Yes" : "No") << '\n';
}