// author: erray
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
  int m;
  cin >> m;
  vector<vector<bool>> can(9, vector<bool>(9));
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    can[x][y] = true;
    can[y][x] = true;
  }
  vector<int> start(8);
  for (int i = 0; i < 8; ++i) {
    cin >> start[i];
    --start[i];
  }
  queue<pair<vector<int>, int>> que; 
  que.emplace(start, 0);
  set<vector<int>> vis;
  vector<int> tar(8);
  iota(tar.begin(), tar.end(), 0);
  while (!que.empty()) {
    auto[v, cost] = que.front();
    que.pop();
    debug(v, cost);
    if (v == tar) {
      cout << cost << '\n';
      exit(0);
    }
    int emp = 0;
    while (count(v.begin(), v.end(), emp)) {
      ++emp;
    }
    debug(emp);
    for (int i = 0; i < 8; ++i) {
      if (can[emp][v[i]]) {
        vector<int> u = v;    
        u[i] = emp;
        if (vis.count(u) == 0) {
          vis.insert(u);
          que.emplace(u, cost + 1);
        }
      }  
    }
  }

  cout << -1 << '\n';

}