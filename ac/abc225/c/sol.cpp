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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      --a[i][j];
    }
  }

  int x = a[0][0] % 7;
  if (x + m > 7) {
    cout << "No\n";
    return 0;
  }

  bool ok = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ok &= (i == 0 || a[i - 1][j] == a[i][j] - 7) && (j == 0 || a[i][j - 1] == a[i][j] - 1);
    }
  }

  cout << (ok ? "Yes" : "No") << '\n';

}