#undef DEBUG
// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

constexpr int B = 4;
constexpr int md0 = int(1e9) + 7;
constexpr int md1 = 999999937;
vector<int> pw0({1});
vector<int> pw1({1});
int pw(int b, int t) {
  assert(b == md0 || b == md1);
  auto& a = (b == md0 ? pw0 : pw1);
  while (int(a.size()) <= t) {
    a.push_back(int(a.back() * 1LL * B % b));
  }
  return a[t];
}

template<int md> struct Hash {
  int val = 0;
  int size = 0;
  Hash() { size = 0,  val = 0; }
  Hash operator+(const Hash& ot) {
    Hash res;
    res.val = int(((1LL * pw(md, size) * ot.val) + val) % md); 
    res.size = size + ot.size;
    return res; 
  }
  Hash operator *(int x) {
    Hash res;
    res.val = int(1LL * val * x % md);
    return res;
  }
};

template<int T> bool operator<(Hash<T> x, Hash<T> y) {
  return x.val < y.val;
}

struct Rhash {
  Hash<md0> h0;
  Hash<md1> h1;
  Rhash() : h0(), h1() { h0.size = h1.size = 0; } 
  Rhash(int x) { 
    h0.val = x;
    h1.val = x;
    h0.size = h1.size = 1;
  }
  Rhash operator+(const Rhash& ot) {
    Rhash res;
    res.h0 = h0 + ot.h0;
    res.h1 = h1 + ot.h1;
    return res;
  }
  Rhash operator*(const int& x) {
    Rhash res;
    res.h0 = h0 * x;
    res.h1 = h1 * x;
    return res;
  }
  Rhash& operator=(const Rhash& ot) {
    h0 = ot.h0;                             
    h1 = ot.h1;
    return *this;
  }
};

bool operator<(Rhash x, Rhash y) {
  return tuple{x.h0, x.h1, x.h0.size} < tuple{y.h0, y.h1, y.h0.size};  
}

/*
string to_string(Rhash x) {
  return to_string(tuple{x.h0.val, x.h1.val, x.h0.size});
}
*/

vector<Rhash> def;

struct SegTree {
  struct node {
    Rhash val;
    int tag = -1;
    void modify(int l, int r, int x) {
      int size = (r - l + 1);
      tag = x;
      val = (def[size] * x);
      val.h0.size = val.h1.size = size;
    }

    node operator+(const node& ot) {
      node res;
      res.val = val + ot.val;
      return res; 
    }
  };
  
  int n;
  vector<node> tree;
  #define init int mid = (l + r) >> 1, rv = v + ((mid - l + 1) << 1)
  void pull(int v, int rv) {
    tree[v] = tree[v + 1] + tree[rv];
  }

  void push(int v, int l, int r) {
    init;
    if (tree[v].tag != -1) {
      tree[v + 1].modify(l, mid, tree[v].tag);
      tree[rv].modify(mid + 1, r, tree[v].tag);
      tree[v].tag = -1;
    }
  }

  void build(int v, int l, int r) {
    if (l == r) {
      tree[v].val = Rhash(1);
      return;
    }
    init;
    build(v + 1, l, mid);
    build(rv, mid + 1, r);
    pull(v, rv);
  }
   
  SegTree(int _n) : n(_n) {
    tree.resize((n << 1) - 1);
    //build(0, 0, n - 1); 
  }

  void modify(int v, int l, int r, int ll, int rr, int x) {
    if (l >= ll && rr >= r) {
      tree[v].modify(l, r, x);
      debug(tree[v].val);
      return;
    }
    init;
    push(v, l, r);
    if (mid >= ll) {
      modify(v + 1, l, mid, ll, rr, x);
    }
    if (mid < rr) {
      modify(rv, mid + 1, r, ll, rr, x);
    }              
    debug(l, r, tree[v].val);
    pull(v, rv);
  }

  node get() {
    return tree[0];
  }
  void modify(int ll, int rr, int x) {
    assert(ll >= 0 && rr < n && ll <= rr && x > 0 && x < 4);   
    modify(0, 0, n - 1, ll, rr, x);
  } 
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  def.resize(N + 1);
  for (int i = 0; i < N; ++i) {
    def[i + 1] = def[i] + Rhash(1);
  }
  debug(def);
  array<string, 3> S;
  for (int i = 0; i < 3; ++i) {
    cin >> S[i];
  }

  int Q;
  string T;
  cin >> Q >> T;
  array<int, 256> cid = {};
  cid['J'] = 0;
  cid['O'] = 1;
  cid['I'] = 2;
  array<vector<int>, 3> vals;
  for (int i = 0; i < 3; ++i) {
    vals[i].resize(N);
    for (int j = 0; j < N; ++j) {
      vals[i][j] = cid[S[i][j]];
    }
  }
  debug(vals);

  vector<bool> vis(27);  
  queue<int> que;
  vector<Rhash> can;
  auto P = [&](int x) {
    if (vis[x]) {
      return;
    }
    vis[x] = true;
    que.push(x);
    vector<int> res(N, 0);
    for (int j = 0; j < 3; ++j) {
      int c = x % 3;
      for (int i = 0; i < N; ++i) {
        res[i] += c * vals[j][i];   
      }
      x /= 3;
    }

    for (auto& e : res) {
      e %= 3;
    }
    debug(res);
    Rhash add;
    for (int i = 0; i < N; ++i) {
      add = add + Rhash(1 + res[i]);
      debug(add);
    }
    can.push_back(add);
  };
  P(1);
  P(3);
  P(9);

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    array<int, 3> me;
    int stv = v;
    for (int i = 0; i < 3; ++i) {
      me[i] = stv % 3;
      stv /= 3;
    }

    for (int add = 0; add < 3; ++add) {
      auto nw = me;
      (nw[add] += 1) %= 3;
      int res = 0;
      for (int j = 2; j >= 0; --j) {
        res *= 3;
        nw[j] = (3 - nw[j]) % 3;
        res += nw[j];
      }
      P(res);
    }
  }

  SegTree st(N);
  for (int i = 0; i < N; ++i) {
    debug(cid[T[i]] + 1);
    st.modify(i, i, cid[T[i]] + 1);  
  }
  
  debug(can);
  auto Can = [&](Rhash x) {
    for (auto e : can) {
      if (e.h0.val == x.h0.val && e.h1.val == x.h1.val) {
        return true;
      }  
    }
    return false;
  };
  
  debug(st.get().val);
  cout << (Can(st.get().val) ? "Yes" : "No") << '\n';
  while (Q--) {
    int L, R;
    char C;
    cin >> L >> R >> C;
    --L, --R;
    debug(L, R, cid[C]);
    st.modify(L, R, cid[C] + 1);
    debug(st.get().val);
    cout << (Can(st.get().val) ? "Yes" : "No") << '\n';
  }
}           	