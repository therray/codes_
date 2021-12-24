// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a((1 << n));
  for (int i = 0; i < (1 << n); ++i) {
    cin >> a[i];
  }
  
  int m = (1 << n);
  vector<array<pair<int, int>, 2>> dp(m);
  for (int i = 0; i < m; ++i) {
    dp[i][0] = {a[i], i};
    dp[i][1] = {-1, -1}; 
  }

  auto Unite = [&](auto x, auto y) {
    array<pair<int, int>, 2> res = {};
    res[0] = max(x[0], y[0]);
    res[1] = max(x[res[0] == x[0]], y[res[0] == y[0]]);
    return res;
  };

  for (int i = 0; i < m; ++i) {
    for (int add = 0; add < n; ++add) {
      if ((i >> add) & 1) {
        continue;
      }
      
      int next = i | (1 << add);
      dp[next] = Unite(dp[next], dp[i]);
    }
  } 

  vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    ans[i] = dp[i][0].first + dp[i][1].first;
  }

  for (int i = 0; i < m - 1; ++i) {
    ans[i + 1] = max(ans[i + 1], ans[i]);
  }
  
  for (int i = 1; i < m; ++i) {
    cout << ans[i] << '\n';
  }
}