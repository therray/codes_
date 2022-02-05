// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
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
      val += md;
    }
  }

  int& operator()() { return val; }
  Mint& operator+=(Mint x) {
    if ((val += x.val) >= md) {
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

map<int, vector<Mint>> pw;

Mint fast_pow(int t, int x) {
  auto& p = pw[t];
  if (p.empty()) {
    p.push_back(1);
  }
  while (int(p.size()) <= x) {
    p.push_back(p.back() * t);
  }
  return p[x];
}

struct Hash {
  Mint val = 0;
  int base = 0;
  Hash(int _base) : base(_base) { }
  bool operator<(Hash x) {
    return val() < x.val();
  } 
  void add(int x, int y) {
    debug(x, y, Mint(y), fast_pow(base, x), fast_pow(base, x) * y);
    val += fast_pow(base, x) * y;
  }
  void operator=(Hash x) {
    val = x.val;
    base = x.base;
  }
};

bool operator==(Hash x, Hash y) {
  return x.val() == y.val();
}

using T = array<Hash, 2>;

string to_string(Hash x) {
  return to_string(x.val);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  const int MAX = *max_element(A.begin(), A.end());              
  vector<int> ct(MAX + 1);
  vector<T> g(N + 1, {Hash(3), Hash(5)});
  auto Add = [&](int c, int x, int y) {
    for (auto& e : g[c]) {
      e.add(x, -ct[x]);
    }
    (ct[x] += y) %= 3;
    for (auto& e : g[c]) {
      e.add(x, ct[x]);
    }
  };                	

  for (int i = 0; i < N; ++i) {
    g[i + 1] = g[i];
    for (int j = 2; j * j <= A[i]; ++j) {
      int t = 0;
      while (A[i] % j == 0) {
        ++t;
        A[i] /= j;
      }
      if (t > 0) {
        Add(i + 1, j, t);
      }
    } 
    if (A[i] != 1) {
      Add(i + 1, A[i], 1);
    }
  }

  debug(g);
  while (Q--) {
    int L, R;
    cin >> L >> R;   
    L -= 1;
    cout << (g[L] == g[R] ? "Yes" : "No") << '\n';
  }
}