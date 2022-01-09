// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;


mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N = int(2e5);
  auto R = [&] {
    return rng() % int(2e5 + 1);
  };
  cout << N << '\n';

  for (int i = 0; i < N; ++i) {
    int x0 = R();
    int x1 = R();
    int y0 = R();
    int y1 = R();
    if (x0 > x1) {
      swap(x0, x1);
    }  
    if (y0 > y1) {
      swap(y0, y1);
    }
    x1 += 1;
    y1 += 1;
    cout << x0 << ' ' << y0 << ' ' << x1 << ' ' << y1 << '\n';
  }
}