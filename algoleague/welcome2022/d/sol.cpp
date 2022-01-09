// author: erray
#undef _GLIBCXX_DEBUG
#undef DEBUG
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
  vector<array<int, 2>> X(N);
  vector<array<int, 2>> Y(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i][0] >> Y[i][0] >> X[i][1] >> Y[i][1];
    --X[i][1];
  }

  const int MAX = int(2e5) + 5;
  const int SQ = int(sqrt(MAX)) + 2;
  vector<vector<pair<int, int>>> a(MAX / SQ + 1);
  for (int i = 0; i < MAX; ++i) {
    a[i / SQ].emplace_back(0, i);
  }
  vector<int> tag(MAX / SQ + 1);
  auto Ct = [&](int x) {
    int s = 1 - tag[x];
    int res = int(lower_bound(a[x].begin(), a[x].end(), pair<int, int>{s + 1, -1}) - lower_bound(a[x].begin(), a[x].end(), pair<int, int>{s, -1})); 
    return res;
  };

  int cur = 0;
  auto Upd = [&](int l, int r, int d) {
    debug(l, r, d);
    int bl = l / SQ;
    int br = r / SQ;
    for (int i = bl; i <= br; ++i) {
      if (i * SQ >= l && (i + 1) * SQ - 1 <= r) {
        cur -= Ct(i); 
        tag[i] += d;
        cur += Ct(i);
      } else {
        for (auto&[e, ind] : a[i]) {
          e += tag[i];
          cur -= (e == 1);
          if (ind >= l && ind <= r) {
            e += d;
          }
          cur += (e == 1);
        }
        tag[i] = 0;
        sort(a[i].begin(), a[i].end());
      }     
    }  
  };

  vector<vector<int>> e(MAX);
  for (int i = 0; i < N; ++i) {
    e[Y[i][0]].push_back(i);
    e[Y[i][1]].push_back(~i);
  }
  long long ans = 0;
  for (int i = 0; i < MAX; ++i) {
    for (auto id : e[i]) {
      if (id < 0) {
        Upd(X[~id][0], X[~id][1], -1);
      } else {
        Upd(X[id][0], X[id][1], +1);      
      }
    } 
    ans += cur;
  }
  cout << ans << '\n';
  debug(clock());
}