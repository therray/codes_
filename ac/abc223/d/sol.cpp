// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> indeg(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    indeg[y] += 1;
  }

  vector<int> p;
  priority_queue<int, vector<int>, greater<int>> que;
  for (int i = 0; i < n; ++i) {
    if (indeg[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    int v = que.top();
    que.pop();
    p.push_back(v);
    for (auto u : g[v]) {
      if (--indeg[u] == 0) {
        que.push(u);
      }
    }
  }

  if (int(p.size()) < n) {
    cout << -1 << '\n';
    return 0;
  }

  for (auto e : p) {
    cout << e + 1 << ' ';
  }
}