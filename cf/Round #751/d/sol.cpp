// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

struct fenwick {
  vector<int> mx;
  int n;
  const int inf = int(1e9);
  fenwick(int _n) : n(_n) {
    mx.resize(n + 1, -inf);
  }

  void modify(int x, int y) {
    x += 1;
    while (x <= n) {
      mx[x] = max(mx[x], y);
      x += x & -x;
    }
  }
  
  int get(int x) {
    x += 1;
    int res = -inf;
    while (x > 0) {
      res = max(res, mx[x]);
      x -= x & -x;  
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<array<int, 2>> a;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (x > d) {
      continue;
    }
    a.push_back({x - d, y - d});
  }
  n = int(a.size());
  vector<int> all;
  for (int i = 0; i < n; ++i) {
    all.push_back(a[i][0]);
    all.push_back(a[i][1]);
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      a[i][j] = int(lower_bound(all.begin(), all.end(), a[i][j]) - all.begin()4);
    }
  }

  vector<int> pref(n * 2 + 1);
  vector<array<int, 2>> new_a;
  for (auto[x, y] : a) {
    if (x <= y) {
      new_a.push_back({x, y});
    } else {
      pref[y + 1] += 1;
    }
  }
  swap(a, new_a);

  for (int i = 0; i < n * 2; ++i) {
    pref[i + 1] += pref[i];
  }
  sort(a.begin(), a.end(), [&](auto x, auto y) {
    return x[1] < y[1];
  });
  fenwick fenw(n * 2 + 1);
  fenw.modify(0, 0);
  int ans = pref[2 * n];
  for (auto[l, r] : a) {
    int res = fenw.get(l) + pref[l + 1];
    ans = max(ans, res);
    fenw.modify(r, res - pref[r]);
  }   

  cout << ans << '\n';
}