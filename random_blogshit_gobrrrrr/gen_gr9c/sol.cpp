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
  vector<vector<int>> all;
  for (int i = 0; i < 10; ++i) {
    int N = rng() % 20 + 5;  
    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin(), p.end(), rng);
    all.push_back(p);
  }
  sort(all.begin(), all.end(), [&](auto x, auto y) {
    return int(x.size()) < int(y.size());
  });
  for (auto e : all) {
    cout << "[";
    for (int i = 0; i < int(e.size()); ++i) {
      cout << e[i] + 1 << array{", ", "]\n"}[i == int(e.size()) - 1];
    }
  }

}