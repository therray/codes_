// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

namespace std {
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    } 

    auto C = [&](int x, int y) {
      if (x < 0 || x >= N || y < 0 || y >= M) {
        return -1;
      }
      return x * M + y;
    };

    vector<int> e(N * M, -1);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        int res = -1;
        if (A[i][j] == 'L') {
          res = C(i, j - 1);
        } else if (A[i][j] == 'R') {
          res = C(i, j + 1);
        } else if (A[i][j] == 'U') {
          res = C(i - 1, j);
        } else {
          res = C(i + 1, j);
        }
        e[C(i, j)] = res;
      }
    }

    debug(e);	

    int n = N * M;
    vector<int> size(n, 1);
    vector<int> vis(n, -1);
    vector<int> from(n, -1);
    for (int i = 0; i < n; ++i) {
      int v = i;
      int t = 0;
      while (v != -1 && vis[v] == -1) {
        vis[v] = t++;
        from[v] = i;
        v = e[v];
      }

      if (v != -1 && from[v] == i) {
        int u = v;
        do {
          size[u] = t - vis[v];
          int bu = u;
          u = e[u];
          e[bu] = -1;             
        } while (u != v);
      }
    }
    debug(size, e);
    
    vector<int> ans(n);
    auto Dfs = y_combinator([&](auto Dfs, int v) -> void {
      if (ans[v] != 0) {
        return;
      }
      if (e[v] != -1) {
        Dfs(e[v]);
        ans[v] = ans[e[v]];
      }
      ans[v] += size[v];
    });

    for (int i = 0; i < n; ++i) {
      Dfs(i);
    }

    auto mx = max_element(ans.begin(), ans.end());
    int res = int(mx - ans.begin());
    cout << 1 + res / M << ' ' << 1 + res % M << ' ' << *mx << '\n';
  }
}