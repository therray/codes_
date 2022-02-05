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
  long long L, R, V;
  cin >> L >> R >> V;
  if (V & 1LL) {
    Mint ans = 0;
    {
      long long left = V ^ 1;
      long long range = left - L + 1;
      if (range >= 3) {
        ans += 1 + (range - 3) / 4;
      }
    }
    {
      long long right = V;
      long long range = R - right + 1;
      if (range >= 1) {
        ans += 1 + (range - 1) / 4;
      } 
    }
    cout << ans() << '\n';
  } else if (V == 0) {
    Mint ans = 0;
    L += L & 1;
    R -= ~R & 1; 
    if (L <= R) {
      long long tot = (R - L + 1) / 4;
      ans += Mint(tot) * (tot + 1) / 2;
    }
    if (L + 2 <= R) {
      long long tot = (R - L - 1) / 4;
      ans += Mint(tot) * (tot + 1) / 2; 
    }
    cout << ans() << '\n';
  } else {
      
  }
}