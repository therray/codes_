// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

template<typename node> struct SegTree {
  int n;
  vector<node> tree;
  node emp;
  SegTree(int _n) : n(_n) {
    tree.resize((n << 1) - 1);
  }

  #define def int mid = (l + r) >> 1, rv = v + ((mid - l + 1) << 1)
  void pull(int v, int rv) {
    tree[v] = tree[v + 1] + tree[rv];
  }
  
  void push(int v, int l, int r) {
    def;
    if (tree[v].tag != emp.tag) {
      tree[v + 1].modify(l, mid, tree[v].tag);
      tree[rv].modify(mid + 1, r, tree[v].tag);
      tree[v].tag = emp.tag; 
    }
  }

  template<typename... T> 
  void modify(int v, int l, int r, int ll, int rr, T... x) {
    if (l >= ll && rr >= r) {
      tree[v].modify(l, r, x...);
      return;
    }  
    def;
    push(v, l, r);
    if (mid >= ll) {
      modify(v + 1, l, mid, ll, rr, x...);
    }
    if (mid < rr) {
      modify(rv, mid + 1, r, ll, rr, x...);
    }
    pull(v, rv);
  }

  node get(int v, int l, int r, int ll, int rr) {
    if (l >= ll && rr >= r) {
      return tree[v];
    }  
    def;
    push(v, l, r);
    if (mid >= ll) {
      if (mid < rr) {
        return get(v + 1, l, mid, ll, rr) + get(rv, mid + 1, r, ll, rr);
      }
      return get(v + 1, l, mid, ll, rr);
    } else {
      return get(rv, mid + 1, r, ll, rr);
    }
  }
  node get(int l, int r) {
    assert(l >= 0 && l <= r && r < n);
    return get(0, 0, n - 1, l, r);
  }
  template<typename... T> void modify(int l, int r, T... x) {
    assert(l >= 0 && l <= r && r < n);
    modify(0, 0, n - 1, l, r, x...);    
  } 
};

const long long inf = (long long) 1e18;
struct node {
  long long sq_sum = 0;
  long long sum = 0;
  array<long long, 2> tag = {inf, 0};
  void modify(int l, int r, array<long long, 2> mdf) {
    if (mdf[0] != inf) {
      long long x = mdf[0];
      tag[0] = x;
      tag[1] = inf;
      sum = (r - l + 1) * x;
      sq_sum = (r - l + 1) * x * x;
    }
    long long x = mdf[1];
    sq_sum += (r - l + 1) * (x * x) + (2 * sum * x);
    sum += (r - l + 1) * x;
    tag[1] += x;  
  }
  node operator+(const node& ot) {
    node res;
    res.sq_sum = sq_sum + ot.sq_sum;
    res.sum = sum + ot.sum;
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  for (int tc = 1; tc <= TT; ++tc) {
    cout << "Case " << tc << ":\n";
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }

    using M = array<long long, 2>;
    SegTree<node> st(N);
    for (int i = 0; i < N; ++i) {
      st.modify(i, i, M{A[i], 0});
    }
    while (Q--) {
      int T, L, R;
      cin >> T >> L >> R;
      --L, --R;
      if (T == 2) {
        cout << st.get(L, R).sq_sum << '\n';
      } else if (T == 1) {
        int X;
        cin >> X;
        st.modify(L, R, M{inf, X});
      } else {
        int X;
        cin >> X;
        st.modify(L, R, M{X, 0});
      }
    }
  }
}