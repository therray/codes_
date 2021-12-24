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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT = 1;
  cout << TT << '\n';
  while (TT--) {
    int N = rng() % 100 + 2;
    N *= 3;
    int S = uniform_int_distribution<int>(N / 3 + 1, N / 3 * 2 - 1)(rng);
    cout << N << '\n' << S << '\n';
    vector<int> all(N);
    iota(all.begin(), all.end(), 0);
    shuffle(all.begin(), all.end(), rng);
    for (int i = 0; i < S; ++i) {
      cout << all[i] + 1 << ' ';
    }
    cout << endl;
  }
}