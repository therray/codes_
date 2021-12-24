// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

template<typename T, typename R = long long> struct Dinics {
  vector<tuple<int, int, T>> es;
  vector<vector<int>> g;
  int n;
  Dinics(int _n) : n(_n) { 
    g.resize(n);
  } 

  void add_edge(int x, int y, T cost, bool directed = false) {
    assert(x >= 0 && y >= 0 && x < n && y < n);           
    int id = int(es.size());
    g[x].push_back(id);
    g[y].push_back(id + 1);
    if (!directed) {
      add_edge(y, x, cost, true);
    }
    es.emplace_back(x, y, cost);
    es.emplace_back(x, y, 0);  
  }

  T Dfs(int v, T add, vector<int>& pt, vector<int>& d, int& s, int& t) {
    if (v == t) {
      return add;
    }
    for (int &i = pt[v]; i < int(g[v].size()); ++i) {
      int id = g[v][i];
      int u = v ^ get<0>(es[id]) ^ get<1>(es[id]);
      if (d[u] == d[v] + 1 && get<2>(es[id]) - flow[id] > 0) {
        T push = Dfs(u, min(add, get<2>(es[id]) - flow[id]), pt, s, t);          
        if (push > 0) {          
          flow[id] += push;
          flow[id ^ 1] -= push;
          return push;                                               
        }
      }
    }  
    return 0;
  }


  long long max_flow(int s, int t) {
    assert(s >= 0 && t >= 0 && s < n && t < n);
    vector<int> d;
    vector<int> pt;
    vector<T> flow(int(es.size()), static_cast<T>(0));
    auto Bfs = [&] {
      d.assign(n, -1);
      d[s] = 0;
      queue<int> que;
      que.push(s);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto id : g[v]) {
          int u = get<0>(es[id]) ^ get<1>(es[id]) ^ v;
          if (d[u] == -1 && get<2>(es[id]) - flow[id] > 0) {
            d[u] = d[v] + 1;
            que.push(u);  
          }
        }
      }

      return d[t] != -1;         		
    };


    R res = 0;
    while (Bfs()) {
      pt.assign(n, 0);       
      while (T push = Dfs(s, numeric_limits<T>::max(), pt, d)) {
        res += push;
      }
    }  
    return res;
  }
};                                          

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  Dinics<int> flow(N);
  for (int i = 0; i < M; ++i) {
    int X, Y, F;
    cin >> X >> Y >> F;
    --X, --Y;
    flow.add_edge(X, Y, F);
  }

  cout << flow.max_flow(0, N - 1) << '\n';
}