// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;


template<int mod> struct Modular {
  int val = 0;
  Modular<mod>(const Modular<mod>& x) {
    val = x.val;
  }
  template<typename T> Modular(T x) {
    if (x >= -mod && x < mod) {
      val = x;
    } else {
      val = x % mod;
    } 
    if (val < 0) {
      val += mod;
    }
  }
  int& operator()() { return val; }
  Modular<mod>& operator +=(Modular<mod> x) {
    if ((val += x.val) >= mod) {
      val -= mod;
    }
    return *this;
  }
  Modular<mod>& operator -=(Modular<mod> x) {
    if ((val -= x.val) < 0) {
      val += mod;
    }
    return *this;
  }
  Modular<mod>& operator *=(Modular<mod> x) {
    val = int((1LL * val * x.val) % mod);
    return *this;
  }

  Modular<mod> inv(Modular<mod> x) {
    int p = mod - 2;
    Modular res = 1;
    while (p > 0) {
      if (p & 1) {
        res *= x;
      }
      x *= x;
      p >>= 1;
    }
    return res;
  } 

  Modular<mod>& operator /=(Modular<mod> x) {
    return *this *= inv(x);
  }

  template<typename O> Modular<mod>& operator += (O x) {
    return *this += Modular<mod>(x);
  }
  template<typename O> Modular<mod>& operator -= (O x) {
    return *this -= Modular<mod>(x);
  }
  template<typename O> Modular<mod>& operator *= (O x) {
    return *this *= Modular<mod>(x);
  }
  template<typename O> Modular<mod>& operator /= (O x) {
    return *this /= Modular<mod>(x);
  }
};

template<int T> Modular<T> operator +(Modular<T> x, Modular<T> y) {
  return x += y;
}
template<int T> Modular<T> operator -(Modular<T> x, Modular<T> y) {
  return x -= y;
}
template<int T> Modular<T> operator *(Modular<T> x, Modular<T> y) {
  return x *= y;
}
template<int T> Modular<T> operator /(Modular<T> x, Modular<T> y) {
  return x /= y;
}

template<int T, typename O> Modular<T> operator +(Modular<T> x, O y) {
  return x + Modular<T>(y);
}
template<int T, typename O> Modular<T> operator -(Modular<T> x, O y) {
  return x - Modular<T>(y);
}
template<int T, typename O> Modular<T> operator *(Modular<T> x, O y) {
  return x * Modular<T>(y);
}
template<int T, typename O> Modular<T> operator /(Modular<T> x, O y) {
  return x / Modular<T>(y);
}

template<int T> string to_string(Modular<T> x) {
  return to_string(x());
}

template<int T, typename O> Modular<T> power(Modular<T> x, O p) {
  Modular<T> res = 1;
  while (p > 0) {
    if (p & 1) {
      res *= x;  
    }
    x *= x;
    p >>= 1;
  }
  return res;
}

constexpr int md = 998244353;
using Mint = Modular<md>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, D;
  cin >> N >> D;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<bool> vis(N + 1);
  for (auto e : A) {
    if (e != -1) {
      vis[e] = true;
    }
  }

  const int MASK = 1 << (D * 2 + 1) ;
  vector<Mint> dp(MASK, 0);
  dp[0] = 1;
  for (int i = 0; i < N; ++i) { 
    vector<Mint> new_dp(MASK, 0);
    for (int j = 0; j < MASK; ++j) {
      for (int c = -D; c <= D; ++c) {
        int pick = i + 1 + c;
        if (pick <= 0 || pick > N || (A[i] == -1 ? vis[pick] : A[i] != pick) || ((j >> (c + D)) & 1)) {
          continue;
        } 
        int new_mask = j | (1 << (c + D));
        new_dp[new_mask >> 1] += dp[j];
      }
    }
    swap(dp, new_dp);  
  } 

  Mint sum = 0;
  for (auto e : dp) {
    sum += e;  
  }
  cout << sum() << '\n';
}