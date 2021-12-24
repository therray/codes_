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
  vector<string> a(3);
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
  }

  bool ok = true;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ok &= (a[i][j] == a[2 - i][2 - j]);
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
}