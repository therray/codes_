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
  cin >> N;
  vector<int> X(N), Y(N), C(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i] >> C[i];
    --C[i];
  }

  vector<vector<int>> ord(4, vector<int>(N));

  for (int i = 0; i < 4; ++i) {
    iota(ord[i].begin(), ord[i].end(), 0);
    sort(ord[i].begin(), ord[i].end(), [&](int x, int y) {
      if (x == y) {
        return false;
      }
      auto F = [&](int xx) { return (i / 2 ? pair{X[xx], Y[xx]} : pair{Y[xx], X[xx]}); };
      return bool(int(F(x) < F(y)) ^ (i % 2));
    });
  }

  int ans = 0;
  array<int, 3> o = {0, 1, 2};
  do {
    for (int ord_f = 0; ord_f < 4; ++ord_f) {
      for (int ord_s = 0; ord_s < 4; ++ord_s) {
        if (ord_s == ord_f) {
          continue;
        }

        auto Can = [&](int x) {
          vector<bool> used(N, false);
          bool ok = true;
          {
            int tx = x;
            for (int i = 0; i < N && tx > 0; ++i) {
              int id = ord[ord_f][i];
              if (!used[id] && C[id] == o[0]) {
                tx -= 1;
              }
              used[id] = true;
            }
          }
        };

        int low = 0, high = N / 3;
        while (low < high) {
          int mid = 1 + ((low + high) >> 1);
          if (Can(mid)) {
            low = mid;
          } else {
            high = mid - 1;
          }
        }
        ans = max(ans, low);
      }
    }
  } while (next_permutation(o.begin(), o.end()));
}