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
  int fact = 1;
  for (int i = 2; i <= 9; ++i) {
    fact *= i;
  }

  int N = 10;
  vector<int> par(N - 1, 0);
  cout << fact - 1 << '\n';
  fact -= 1;
  while (fact--) {
    cout << N << '\n';
    int p = N - 2;
    while (par[p] == p) {
      par[p] = 0;
      --p;
    }
    par[p] += 1;
    vector<int> id(N);
    iota(id.begin(), id.end(), 1);
    //shuffle(id.begin(), id.end(), rng);
    for (int i = 0; i < N - 1; ++i) {
      cout << id[i + 1] << ' ' << id[par[i]] << '\n';
    }
  }

}