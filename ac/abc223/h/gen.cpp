// author: erray
#include <bits/stdc++.h>
 
using namespace std;

mt19937_64 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count()); 
template<typename T> T Rand(T l, T r) {
  return uniform_int_distribution<T>(l, r)(rng);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  n = Rand(1, int(4e5));
  q = Rand(1, int(2e5));
  cout << n << ' ' << q << '\n';
  for (int i = 0; i < n; ++i) {
    cout << Rand(1LL, (1LL << 60) - 1) << ' ';
  }

  for (int i = 0; i < q; ++i) {
    int l = Rand(1, n);
    int r = Rand(1, n);
    cout << min(l, r) << ' ' << max(l, r) << ' ' << Rand(1LL, (1LL << 60) - 1) << '\n';
  }
}