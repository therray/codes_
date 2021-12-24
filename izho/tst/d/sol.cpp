// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  long long D;
  cin >> N >> D;
  map<long long, long long> delt;
  auto Add = [&](long long l, long long r, int c) {
    assert(l >= 0 && l <= r && r < D);
    delt[l] += c;
    delt[r + 1] -= c;
  };

  for (int i = 0; i < N; ++i) {
    long long L, R;
    cin >> L >> R;
    if (R - L + 1 >= D) {
      Add(0, D - 1, +1);
      continue;
    }

    long long ml = L % D;
    long long mr = R % D;
    if (ml <= mr) {
      Add(ml, mr, +1);
    } else {
      Add(0, D - 1, +1);
      if (mr + 1 <= ml - 1) {
        Add(mr + 1, ml - 1, -1);  
      }
    }
  }

  pair<long long, long long> mx = {D + 1, D + 1};
  long long sum = 0;
  for (auto[x, c] : delt) {
    sum += c;
    mx = min(mx, pair{-sum, x});
  }
  cout << -mx.first << ' ' << mx.second << '\n';
}