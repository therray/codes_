// author: erray
#undef __GLIBCXX_DEBUG
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

vector<array<int, 2>> es;
vector<vector<int>> g;
vector<int> flow;
vector<int> d;
vector<int> pt;
 
int s = 0, t;

bool bfs() {
  fill(d.begin(), d.end(), -1);
  queue<int> que;
  que.push(s);    
  d[s] = 0;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto id : g[v]) {
      int u = es[id][0];
      if (d[u] == -1 && es[id][1] - flow[id] > 0) {
        d[u] = d[v] + 1;
        que.push(u);
      }
    }
  }
  return d[t] != -1;
}

int dfs(int v, int push) {
  if (v == t) {
    return push;
  }

  for (int &i = pt[v]; i < int(g[v].size()); ++i) {
    int id = g[v][i];        
    auto[u, cap] = es[id];
    if (d[u] == d[v] + 1 && cap - flow[id] > 0) {
      int pushed = dfs(u, min(push, cap - flow[id]));
      if (pushed > 0) {
        flow[id] += pushed;
        flow[id ^ 1] -= pushed;
        return pushed;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  es.resize(M * 2);
  g.resize(N * 2);
  flow.resize(M * 2);
  d.resize(N * 2);
  pt.resize(N);
  for (int i = 0; i < M; ++i) {
    int X, Y, C;
    cin >> X >> Y >> C;
    --X, --Y;
    es[i * 2] = {Y, C};
    es[i * 2 + 1] = {X, C};      
    g[X].push_back(i * 2);
    g[Y].push_back(i * 2 + 1);
  }  

  t = N - 1;
  long long ans = 0;
  while (bfs()) {
    fill(pt.begin(), pt.end(), 0);
    while (int add = dfs(s, numeric_limits<int>::max())) {
      ans += add;
    }
  }
  cout << ans << '\n';
  //cerr << clock() << endl;
}