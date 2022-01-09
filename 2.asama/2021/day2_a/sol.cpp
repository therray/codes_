// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

//you can define md with template or inside the struct for other uses 
constexpr int md = int(1e9) + 7;
struct Mint {
  int val = 0;  
  Mint() : val{} {}
  template<typename T> Mint(T x) {
    if (x >= -md && x < md) {
      val = x;
    } else {
      val = x % md;
    }
    if (val < 0) {
      val += x;
    }
  }

  int& operator()() { return val; }
  Mint& operator+=(Mint x) {
    if ((val += x.val) > md) {
      val -= md;
    }
    return *this;
  }
  Mint& operator-=(Mint x) {
    if ((val -= x.val) < 0) {
      val += md;
    }
    return *this;
  }
  Mint& operator*=(Mint x) {
    val = int((1LL * val * x.val) % md);      
    return *this;
  }

  Mint inv(Mint x) {
    int m = md - 2;
    Mint res = 1; 
    while (m > 0) {
      if (m & 1) {
        res *= x;
      }
      x *= x;
      m >>= 1;
    }  
    return res;
  }

  Mint& operator/=(Mint x) {
    return *this *= inv(x);
  }
};

Mint operator+(Mint x, Mint y) {
  return x += y;
}
Mint operator-(Mint x, Mint y) {
  return x -= y;
}
Mint operator*(Mint x, Mint y) {
  return x *= y;
}
Mint operator/(Mint x, Mint y) {
  return x /= y;
}
string to_string(Mint x) {
  return to_string(x());
}
template<typename T> Mint power(Mint x, T p) {
  Mint res = 1;
  while (p > 0) {
    if (p & 1) {
      res *= x;
    }
    x *= x;
    p >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, K, M;
  cin >> N >> K >> M;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }

  vector<int> A(N, -1);
  for (int i = 0; i < M; ++i) {
    int V, X;
    cin >> V >> X;
    --V, --X;
    A[V] = X;
  }

  vector<int> size(N, 1);
  function<void(int)> Pre = [&](int v) {
    for (auto u : g[v]) {
      g[u].erase(find(g[u].begin(), g[u].end(), v));
      Pre(u);
      size[v] += size[u];
    }
  };
  Pre(0);
  vector<vector<Mint>> dp(N);
  function<void(int)> Dfs = [&](int v) {
    for (int i = 1; i < int(g[v].size()); ++i) {
      if (size[g[v][i]] > size[g[v][0]]) {
        swap(g[v][i], g[v][0]);
      }
    }
    for (auto u : g[v]) {
      Dfs(u);
      dp[v].resize(K, 1);
      for (int i = 0; i < K; ++i) {
        dp[v][i] *= dp[u][i];
      }
      debug(dp[v], dp[u]);
      dp[u].clear();
    }
    if (dp[v].empty()) {
      dp[v].resize(K);
      for (int i = 0; i < K; ++i) {
        dp[v][i] = i + 1;
      }
    } 

    if (A[v] != -1) {
      for (int i = 0; i <= A[v]; ++i) {
        dp[v][i] = 0;
      }
    } else {
      Mint sum = 0;
      for (int i = 0; i < K; ++i) {
        if (i < K - 1) {
          sum += dp[v][i + 1];
        }
        dp[v][i] = sum + (K - i - 1) * dp[v][min(K - 1, i + 1)];
      }
    }
  };
  Dfs(0);
  cout << dp[0][K - 1]() << '\n';
}
