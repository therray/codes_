// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

template<typename T, typename R = int64_t> struct Dinic {
  vector<pair<int, T>> es;
  vector<vector<int>> g;
  vector<T> flow;
  vector<int> d;
  vector<int> pt;
  int n;
  Dinic(int _n) : n(_n) {
    g.resize(n);
  }

  void add_edge(int v, int u, T cap = 1, bool directed = true) {
    int id = int(es.size());
    es.push_back(pair<int, T>{u, cap});
    es.push_back(pair<int, T>{v, directed ? 0 : cap});
    g[v].push_back(id);
    g[u].push_back(id ^ 1);
  }

  T dfs(int v, T push, int& t) {
    if (v == t) {
      return push;  
    }
    for (int &i = pt[v]; i < int(g[v].size()); ++i) {
      int id = g[v][i];
      auto[u, cap] = es[id];
      if (d[u] == d[v] + 1 && flow[id] < cap) {
        T res = dfs(u, min(push, cap - flow[id]), t);   
        if (res > 0) {
          flow[id] += res;
          flow[id ^ 1] -= res;
          return res;
        }
      }
    }
    return 0;
  }

  R max_flow(int s, int t) {
    flow.assign(int(es.size()), 0);
    d.resize(n);
    pt.resize(n);
    auto Bfs = [&] {
      queue<int> que;
      fill(d.begin(), d.end(), -1);
      d[s] = 0;
      que.push(s);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto id : g[v]) {
          auto[u, cap] = es[id];
          if (d[u] == -1 && flow[id] < cap) {
            d[u] = d[v] + 1;
            que.push(u);
          }    
        }
      }
      return d[t] != -1;
    };
    R res = 0;
    while (Bfs()) {
      fill(pt.begin(), pt.end(), 0);
      while (T add = dfs(s, numeric_limits<T>::max(), t)) {
        res += add;
      } 
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  long long sum = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    sum += max(A[i], 0);
  }
  
  Dinic<long long> flow(N + 2);
  for (int i = 0; i < N; ++i) {
    if (A[i] < 0) {
      flow.add_edge(0, i + 1, -A[i]);
    } else {
      flow.add_edge(i + 1, N + 1, A[i]); 
    }

    for (int j = i + 1; j <= N; j += i + 1) {
      flow.add_edge(i + 1, j, (long long) 1e18);
    }
  }
  
  cout << sum - flow.max_flow(0, N + 1) << '\n';
}