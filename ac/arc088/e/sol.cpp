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
  vector<int> a;
  int n;
  fenwick(int _n) : n(_n) {
    a.resize(n + 1, 0);
  }

  int get(int x) {
    x += 1;
    int res = 0;
    while (x > 0) {
      res += a[x];
      x -= x & -x;
    }
    return res;
  }

  void modify(int x, int v) {
    x += 1;
    while (x <= n) {
      a[x] += v;
      x += x & -x;
    }
  }

  int get(int l, int r) {
    return get(r) - (l == 0 ? 0 : get(l - 1));
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = int(s.size());
  vector<deque<int>> at(26);
  for (int i = 0; i < n; ++i) {
    at[s[i] - 'a'].push_back(i);
  }

  int ct = 0;
  for (auto e : at) {
    ct += int(e.size()) % 2;
  }

  if (ct > 1) {
    cout << -1 << '\n';
    return 0;
  }
  
  vector<int> p(n, -1);
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    if (p[i] != -1) {
      continue;
    }
    int c = s[i] - 'a';
    debug(i, c, at);
    if (int(at[c].size()) == 1) {
      p[i] = n / 2; 
      continue;
    }
    p[i] = cur;
    p[at[c].back()] = n - 1 - cur;
    at[c].pop_back();
    at[c].pop_front();
    cur += 1;
  }
  debug(p);

  fenwick bit(n);
  long long ans = 0;
  for (int  i = n - 1; i >= 0; --i) {
    ans += bit.get(p[i]);
    bit.modify(p[i], +1);
  }            
  cout << ans << '\n';
}