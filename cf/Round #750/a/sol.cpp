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
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    b %= 2;
    c %= 2;
    int f = (c * 3) - (2 * b);
    if (f < 0) {
      f *= -1;
    }
    a -= f;
    cout << (a >= 0 && a % 2 == 0 ? 0 : 1) << '\n';
  }
}