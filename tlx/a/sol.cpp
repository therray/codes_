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
  int N, K;
  cin >> N >> K;
  long long ans = 1;
  --N;
  while (N--) {
    if (ans % K == 0) {
      ans *= 2;
    } else {
      ans += 1;
    }
  }
  cout << ans << '\n';
}
