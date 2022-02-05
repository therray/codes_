// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
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
  int N, M;
  cin >> N >> M;
  vector<vector<vector<Mint>>> dp(M + 1, vector<vector<Mint>>(M + 1, vector<Mint>(M + 1, 0)));
  dp[M][M][M] = 1;
  for (int it = 0; it < N; ++it) {
    vector<vector<vector<Mint>>> new_dp(M + 1, vector<vector<Mint>>(M + 1, vector<Mint>(M + 1, 0)));
    for (int i = 0; i < M; ++i) {
      for (int f = 0; f <= M; ++f) {
        for (int s = 0; s <= M; ++s) {
          for (int t = i; t <= M; ++t) {
            int nf = min(f, i);
            int ns = min(s, (f < i ? i : M));
            int nt = min(t, (s < i ? i : M));
            new_dp[nf][ns][nt] += dp[f][s][t];
          }
        }
      }
    }
    swap(dp, new_dp);
  }
  Mint ans = 0;
  for (auto a : dp) {
    for (auto b : a) {
      for (int i = 0; i < M; ++i) {
        ans += b[i];
      }
    }
  }
  cout << ans() << '\n';
}