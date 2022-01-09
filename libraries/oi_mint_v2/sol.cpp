// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

constexpr int md = int(1e9 + 7);
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

vector<Mint> fac({1}), inv_fac({1});
void fill_fact(int n) {
  while (int(fac.size()) <= n) {
    fac.push_back(fac.back() * int(fac.size()));
  }
  inv_fac.resize(n + 1);
  inv_fac[n] = 1 / fac[n];
  for (int i = n; i > 1; --i) {
    inv_fac[i - 1] = inv_fac[i] * i;
  }
}

Mint C(int x, int y) {
  assert(x >= 0 && y >= 0);
  if (y > x) {
    return 0;
  }
  return fac[x] * inv_fac[x - y] * inv_fac[y];
}

Mint P(int x, int y) {
  assert(x >= 0 && y >= 0);
  if (y > x) {
    return 0;
  }  
  return fac[x] * inv_fac[x - y];
}
  

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}