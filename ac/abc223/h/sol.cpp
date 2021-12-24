// author: erray
#include <bits/stdc++.h>
 
using namespace std;

template<typename T> struct XorBasis {
  vector<T> a;
  int n;
  XorBasis(int _n) : n(_n) {
    a.resize(n, 0);
  } 

  bool insert(T x, bool keep = true) {
    for (int i = n - 1; i >= 0; --i) {
      if (~(x >> i) & 1) {
        continue;
      } 
      if (a[i] == 0) {
        if (keep) {
          a[i] = x;
        }
        return keep;
      }
      x ^= a[i];
    }
    return !keep;
  }

  bool can(T x) {
    return insert(x, false);
  }
};

 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int q;
  cin >> q;
  vector<vector<tuple<int, long long, int>>> qs(n);
  for (int i = 0; i < q; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    --l, --r;
    qs[r].emplace_back(l, x, i);
  }

    
  cerr << clock() << " ms" << '\n';
}