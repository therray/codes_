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
  int l = 1;
  int r = int(1e9);
  for (int i = 0; i < N; ++i) {
    int L, R;
    cin >> L >> R;
    l = max(L, l);
    r = min(r, R);
    cout << max(0, (l - r + 1) / 2) << '\n';
  }
}