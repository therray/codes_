// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;


mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N = Rand(5, 15);
  int K = Rand(1, N);
  cout << N << ' ' << K << '\n';
  for (int i = 1; i < N; ++i) {
    cout << i + 1 << ' ' << Rand(1, i) << '\n';
  }

}