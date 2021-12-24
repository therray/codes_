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
  int n;
  cin >> n;
  vector<int> X(n), Y(n);
  for (int i = 0; i < n; ++i) {
    cin >> X[i] >> Y[i];
  }

  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) {
    return pair{X[x] + Y[x], X[x]} < pair{X[y] + Y[y], X[y]};
  });

  set<pair<int, int>> mp;
  for (auto i : ord) {
    int x = X[i];
    int y = Y[i];
    if (!mp.count({x - 1, y + 1}) && !mp.count({x, y - 1}) && !mp.count({x - 1, y})) {
      mp.emplace(x, y);
    }
  }
  cout << int(mp.size()) << '\n';
}