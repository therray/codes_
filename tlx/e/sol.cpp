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
constexpr int md = 998244353;
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
  int N;
  cin >> N;
  vector<Mint> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i]();
  }
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }
  vector<int> par(N, -1);
  vector<int> size(N);
  vector<Mint> sum(N);
  function<void(int)> Dfs = [&](int v) {
    for (auto u : g[v]) {
      if (u != par[v]) {
        par[u] = v;
        size[v] += 1;
        sum[v] += A[u];
        Dfs(u);
      }
    }
  };
  Dfs(0);
  vector<Mint> upd(N);
  auto Get = [&](int v) {
    return A[v] + (par[v] == -1 ? 0 : upd[par[v]]);  
  };

  int Q;
  cin >> Q;
  while (Q--) {
    int T, V;
    cin >> T >> V;
    --V;
    if (T == 2) {
      Mint ans = upd[V] * size[V] + sum[V] + (par[V] == -1 ? 0 : Get(par[V]));
      cout << ans() << '\n';
    } else {
      Mint add = Get(V);
      if (par[V] != -1) {
        A[par[V]] += add;
        if (par[par[V]] != -1) {
          sum[par[par[V]]] += add;
        }
      }
      upd[V] += add;
    }
  }
}
