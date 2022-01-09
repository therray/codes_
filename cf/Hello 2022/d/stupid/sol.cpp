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
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<vector<int>> val(N * 2, vector<int>(N * 2));
    for (int i = 0; i < N * 2; ++i) {
      for (int j = 0; j < N * 2; ++j) {
        cin >> val[i][j];
      }
    }

    array<vector<vector<int>>, 2> mats;
    long long start = 0;
    for (int m = 0; m < 2; ++m) {
      mats[m].resize(N, vector<int>(N));
      for (int i = 0; i < N * 2; ++i) {
        for (int j = 0; j < N * 2; ++j) {
          if ((i < N) == (j < N)) {
            start += val[i][j];
            val[i][j] = 0;
          } else if ((i < N) == m) {
            mats[m][i - N * (m ^ 1)][j - N * m] = val[i][j];                                  
          }
        }
      }
    }
    debug(start);
    debug(mats);
    const long long inf = (long long) 1e17;
    long long ans = inf;
    const array<int, 2> moves[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto[ai, aj] : moves) {
      array<vector<long long>, 2> pref;
      pref.fill(vector<long long>(N + 1));
      for (int m = 0; m < 2; ++m) {
        int i = (ai < 0 ? N - 1 : 0), j = (aj < 0 ? N - 1 : 0);
        for (int it = 0; it < N; ++it) {
          long long sum = 0;
          for (int ind = 0; ind < N; ++ind) {
            sum += (ai == 0 ? mats[m][ind][j] : mats[m][i][ind]);
          }
          pref[m][it + 1] = pref[m][it] + sum;
          i += ai;
          j += aj;
        }
      }
      debug(ai, aj, pref);

      long long res = inf;
      for (int i = 0; i <= N; ++i) {
        res = min(res, pref[0][i] - pref[1][i]); 
      }
      ans = min(ans, res + pref[1][N]);
    }
    cout << start + ans << '\n';
  }
}