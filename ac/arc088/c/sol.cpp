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
  long long x, y;
  cin >> x >> y;
  int ans = 0;
  while (x <= y) {
    x *= 2;
    ans += 1;
  }           
  cout << ans << '\n';
}