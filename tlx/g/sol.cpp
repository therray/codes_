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
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<vector<int>> mx(N, vector<int(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      mx[i][j] = (i == j ? i : A[mx[i][j - 1]] > A[j] ? mx[i][j] : j);
    }
  }
  vector<vector<vector<Mint>>> dp(N, vector<vector<Mint>>(N, vector<Mint>(K + 1)));
  vector<vector<vector<Mint>>> left(N, vector<vector<Mint>>(N, vector<Mint>(K + 1)));  
  vector<vector<vector<Mint>>> right(N, vector<vector<Mint>>(N, vector<Mint>(K + 1)));  
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) {
      //add one because you can take them all

      for (int k = 0; k <= K; ++k) {
        right[i][j][k] = (i < N - 1 ? right[i + 1][j][k] : Mint(0)) + dp[i][j][k];
        left[i][j][k] = (j > 0 ? left[i][j - 1] : Mint(0)) + dp[i][j][k];
      } 
    }
  }

  cout << dp[0][N - 1][K]() << '\n';
}