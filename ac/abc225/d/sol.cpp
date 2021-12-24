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
  int n, q;
  cin >> n >> q;
  vector<int> next(n, -1);
  vector<int> prev(n, -1);
  while (q--) {
    int t, x;
    cin >> t >> x;
    --x;
    if (t != 3) {
      int y;
      cin >> y;
      --y;
      if (t == 1) {
        next[x] = y;
        prev[y] = x;
      } else {
        next[x] = prev[y] = -1;
      }
    } else {
      while (prev[x] != -1) {
        x = prev[x];
      }
      vector<int> ans;
      while (x != -1) {
        ans.push_back(x);
        x = next[x];
      }
      cout << int(ans.size()) << ' ';
      for (auto e : ans) {
        cout << e + 1 << ' ';
      }
      cout << '\n';
    }
  }
}