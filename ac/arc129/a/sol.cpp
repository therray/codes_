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
  long long N, L, R;
  cin >> N >> L >> R;
  long long ans = 0;
  for (int i = 61; i >= 0; --i) {
    long long l = (1LL << i);
    if (N & l) {
      long long r = (l << 1) - 1;
      ans += max(0LL, 1 + min(r, R) - max(l, L));
    }
  }
  cout << ans << '\n';
}