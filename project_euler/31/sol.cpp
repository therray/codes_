// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int C[] = {1, 2, 5, 10, 20, 50, 100, 200};
  vector<long long> dp(200 + 1);
  dp[0] = 1;
  for (auto e : C) {
    vector<long long> new_dp = dp;
    for (int j = e; j <= 200; j += e) {
      for (int i = 0; i + j <= 200; ++i) {
        new_dp[i + j] += dp[i];
      }
    }
    swap(dp, new_dp);
  }
  cout << dp[200] << '\n';
}