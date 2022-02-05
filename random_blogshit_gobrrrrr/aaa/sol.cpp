// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N = 10;
  vector<int> X(N);
  vector<int> Y(N);
  for (int i = 0; i < N; ++i) {
    auto G = [&] {
      return uniform_int_distribution<int>(0, int(pow(i + 1, 5)) * 4)(rng);   
    };
    X[i] = G();
    Y[i] = G();
    if (X[i] > Y[i]) {
      swap(X[i], Y[i]);
    }
    cout << "(" << X[i] << ", " << Y[i] << ")\n";
  }
  cout << '\n';
  
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int res = gcd(X[i], Y[i]) + 1;
    cout << "(" << X[i] << ", " << Y[i] << "): " << res << '\n';
    ans += res;
  }
  cout << ans << '\n';
}