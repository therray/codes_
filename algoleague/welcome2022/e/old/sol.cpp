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

struct fenwick {
  int n;
  vector<int> tree;
  fenwick(int _n) : n(_n) {
    tree.resize(n + 1);
  }

  int get(int x) {
    x += 1;
    int res = 0;
    while (x > 0) {
      res += tree[x];
      x = x & (x - 1);
    }
    return res;
  }

  void modify(int x, int d) {
    x += 1;
    while (x <= n) {
      tree[x] += d;
      x += x & -x;
    }
  }

  int suf(int x) {
    return get(n - 1) - get(x);
  }
};

template<typename node> struct SegTree {
  node emp;
  inline void push(int v, int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    if (tree[v].tag() != emp.tag()) {
      tree[rv].modify(mid + 1, r, tree[v].tag);
      tree[v + 1].modify(l, mid, tree[v].tag);
    }
    tree[v].tag = emp.tag;
  }

  inline void pull(int v, int rv) {
    tree[v] = tree[v + 1] +  tree[rv];
  }

  int n;
  vector<node> tree;

  template<typename T> void build(int v, int l, int r, const vector<T> vv) {
    if (l == r) {
      tree[v].modify(l, r, vv[l]);
      return;
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    build(v + 1, l, mid, vv);
    build(rv, mid + 1, r, vv);
    pull(v, rv);
  }

  node get(int v, int l, int r, int ll, int rr) {
    if (l >= ll && rr >= r) {
      return tree[v];
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, l, r);

    if (mid >= ll && mid < rr) {
      return get(v + 1, l, mid, ll, rr) + get(rv, mid + 1, r, ll, rr);
    }
    if (mid >= ll) {
      return get(v + 1, l, mid, ll, rr);
    }
    return get(rv, mid + 1, r, ll, rr);
  }

  template<typename R, typename... T> R get(int v, int l, int r, int ll, int rr, function<R(const R&, const R&)> f, const T&... t) {
    if (l >= ll && rr >= r) {
      return tree[v].get(l, r, t...);
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, l, r);

    if (mid >= ll && mid < rr) {
      return f(get(v + 1, l, mid, ll, rr, t...), get(rv, mid + 1, r, ll, rr, t...));
    }
    if (mid >= ll) {
      return get(v + 1, l, mid, ll, rr, t...);
    }
    return get(rv, mid + 1, r, ll, rr, t...);

  }

  template<typename... T> void modify(int v, int l, int r, int ll, int rr, const T&... t) {
    if (l >= ll && rr >= r) {
      tree[v].modify(l, r, t...);
      return;
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, l, r);

    if (mid >= ll) {
      modify(v + 1, l, mid, ll, rr, t...);
    }
    if (mid < rr) {
      modify(rv, mid + 1, r, ll, rr, t...);
    }
    pull(v, rv);
  }

  template<typename... T> void set_modify(int v, int l, int r, int tar, const T&... t) {
    if (l == r) {
      tree[v] = emp;
      tree[v].modify(l, r, t...);
      return;
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, l, r);

    if (mid >= tar) {
      set_modify(v + 1, l, mid, tar, t...);
    }
    if (mid < tar) {
      set_modify(rv, mid + 1, r, tar, t...);
    }
    pull(v, rv);
  }

  int find_first_exact(int v, int l, int r, const function<bool(const node&)> f) {
    if (!f(tree[v])) return -1;
    if (l == r) {
      return l;
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, l, r);

    int res = -1;
    if (f(tree[v + 1])) {
      res = find_first_exact(v + 1, l, mid, f);
    } else {
      res = find_first_exact(rv, mid + 1, r, f);
    }
    assert(res != -1);
    return res;
  }

  int find_last_exact(int v, int l, int r, const function<bool(const node&)> f) {
    if (!f(tree[v])) return -1;
    if (l == r) {
      return l;
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, l, r);

    int res = -1;
    if (f(tree[rv])) {
      res = find_last_exact(rv, mid + 1, r, f);
    } else {
      res = find_last_exact(v + 1, l, mid, f);
    }
    assert(res != -1);
    return res;
  }

  int find_first(int v, int l, int r, int ll, int rr, const function<bool(const node&)> f) {
    if (l >= ll && rr >= r) {
      return find_first_exact(v, l, r, f);
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, l, r);

    int res = -1;
    if (mid >= ll) {
      res = find_first(v + 1, l, mid, ll, rr, f);
    }
    if (res == -1 && mid < rr) {
      res = find_first(rv, mid + 1, r, ll, rr, f);
    }
    return res;
  }

  int find_last(int v, int l, int r, int ll, int rr, const function<bool(const node&)> f) {
    if (l > rr || r < ll) {
      return -1;
    }
    if (l >= ll && rr >= r) {
      return find_last_exact(v, l, r, f);
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, l, r);

    int res = -1;
    if (mid < rr) {
      res = find_last(rv, mid + 1, r, ll, rr, f);
    }
    if (res == -1 && mid >= ll) {
      res = find_last(v + 1, l, mid, ll, rr, f);
    }
    return res;
  }

  /*==========================================================================*/


  SegTree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize((n << 1) - 1);
  }

  void clear() {
    tree.assign((n << 1) - 1, node{});  
  }
  
  template<typename T> SegTree(vector<T> v) : n((int) v.size()) {
    tree.resize(n * 2 - 1);
    build(0, 0, n - 1, v);
  }

  node get(int ind) {
    assert(ind >= 0 && ind < n);
    return get(0, 0, n - 1, ind, ind);
  }

  node get(int l, int r) {
    assert(l >= 0 && l < n && r >= 0 && r < n && r >= l);
    return get(0, 0, n - 1, l, r);
  }

  template<typename R, typename... T> R get(int l, int r, function<R(const R&, const R&)> f, T... t) {
    assert(l >= 0 && l < n && r >= 0 && r < n && r >= l);
    return get<R>(0, 0, n - 1, l, r, f, t...);
  }

  template<typename... T> void modify(int l, int r, T... t) {
    assert(l >= 0 && l < n && r >= 0 && r < n && r >= l);
    modify(0, 0, n - 1, l, r, t...);
  }

  template<typename... T> void point_modify(int ind, T... t) {
    assert(ind >= 0 && ind < n);
    modify(0, 0, n - 1, ind, ind, t...);
  }

  template<typename... T> void set_modify(int ind, T... t) {
    assert(ind >= 0 && ind < n);
    set_modify(0, 0, n - 1, ind, t...);
  }

  int find_first(int l, int r, const function<bool(const node&)> f) {
    assert(l >= 0 && l < n && r >= 0 && r < n && r >= l);
    return find_first(0, 0, n - 1, l, r, f);
  }

  int find_last(int l, int r, const function<bool(const node&)> f) {
    assert(l >= 0 && l < n && r >= 0 && r < n && r >= l);
    return find_last(0, 0, n - 1, l, r, f);
  }

  int find_first(const function<bool(const node&)> f) {
    return find_first(0, 0, n - 1, 0, n - 1, f);
  }

  int find_last(const function<bool(const node&)> f) {
    return find_last(0, 0, n - 1, 0, n - 1, f);
  }
};

struct node {
  //variables default values should be uneffective
  Mint val = 0;
  Mint tag = 1;
  void modify(int l, int r, Mint x) {
    assert(l == l && r == r); // no to warnings
    tag *= x;
    val *= x;
  }

  void modify(int l, int r, Mint x, bool st) {
    val = x;
  }

  node operator+ (const node& x) {
    node res;
    res.val = val + x.val;
    return res;
  }

  int get (int l, int r) {
    return l + r;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<array<int, 2>> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i][0] >> A[i][1];
  }
  sort(A.begin(), A.end());
  vector<int> ord(N);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) {
    return A[x][1] > A[y][1];
  });

  SegTree<node> add(N);
  fenwick ct(N);
  Mint ans = 0;
  for (auto i : ord) {
    Mint pw3 = power(Mint(3), A[i][0]);
    Mint pw5 = power(Mint(5), A[i][1]);
    add.modify(i, i, pw3 * power(Mint(2), ct.suf(i)), true);
    ans += add.get(0, i).val * pw5;
    ct.modify(i, +1);
    if (i > 0) {
      add.modify(0, i - 1, 2);
    }
  }
  debug(ans);
  #ifdef DEBUG 
    Mint res = 0;
    for (int mask = 1; mask < (1 << N); ++mask) {
      array<int, 2> mn = {int(1e9), int(1e9)};
      for (int i = 0; i < N; ++i) {
        if ((mask >> i) & 1) {
          mn[0] = min(A[i][0], mn[0]);
          mn[1] = min(A[i][1], mn[1]);
        }
      }
      res += power(Mint(3), mn[0]) * power(Mint(5), mn[1]);
    }
    debug(res);
    assert(res() == ans());
  #endif

  cout << ans() << '\n';
}                        