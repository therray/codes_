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
  set<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x = i + j;
      int y = n - i - 1 + j;
      cout << i << ' ' << j << ' ' << i + j << ' ' << n - i - 1 + j << '\n';
      assert(!st.count({x, y}));
      st.insert({x, y});
    }
  }

}