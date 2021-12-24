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
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int X;
    cin >> X;
    bool ok = false;
    for (int j = 1; j <= X; ++j) {
      for (int k = 1; k <= X; ++k) {
        ok |= (3 * (j + k) + j * k * 4 == X);
      }
    }

    ans += !ok;
  }
  cout << ans << '\n';
}