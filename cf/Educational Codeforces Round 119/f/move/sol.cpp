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
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
      cin >> P[i];
    }


    vector<array<int, 4>> dp(N + 1, {-1, -1, -1, -1});
    dp[0][0] = 0;  
    int lst = -N - 5;
    for (int i = 0; i < int(P.size()); ++i) {
      for (int prev = 0; prev < 2; ++prev) {
        for (int next = 0; next < 2; ++next) {
          for (int start = 0; start < 2; ++start) {
            int prev_val = lst * (prev ? -1 : 1);
            int next_val = P[i] * (next ? -1 : 1);
            int next_d = start + (prev_val > next_val);
            if (next_d < 2 && dp[i][prev * 2 + start] != -1 && dp[i + 1][next * 2 + next_d] == -1) {
              dp[i + 1][next * 2 + next_d] = prev * 2 + start; 
            }  
          }
        }
      }
      lst = P[i];
    }
    debug(dp);

    int v = 0;
    while (v < 4 && dp[N][v] == -1) {
      ++v;
    }

    debug(v);
    if (v == 4) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      vector<int> ans(N);
      for (int i = N - 1; i >= 0; --i) {
        ans[i] = P[i] * (v / 2 ? -1 : 1);
        v = dp[i + 1][v];
      }

      for (auto e : ans) {
        cout << e << ' ';
      }
      cout << '\n';
    }
  }
}