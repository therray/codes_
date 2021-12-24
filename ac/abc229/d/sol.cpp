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
  string S;
  int K;
  cin >> S >> K;
  int N = int(S.size());
  vector<int> pref(N + 1);
  int p = 0;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    pref[i + 1] = pref[i] + (S[i] == '.');
    while (pref[i + 1] - pref[p] > K) {
      ++p;
    }
    ans = max(ans, i - p + 1);
  }
  cout << ans << '\n';
}