// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  auto Can = [&](long long x) {
    vector<bitset<51>> dp(n + 1);
    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
      long long sum = 0;
      for (int j = i; j < n; ++j) {
        sum += a[j];
        if ((x & sum) == x) { 
          dp[j + 1] |= (dp[i] << 1);
        }
      }
    }
    return dp[n][k];
  };

  long long ans = 0;
  for (long long b = (1LL << 55); b > 0; b >>= 1) {
    if (Can(ans | b)) {
      ans |= b;
    }
  }
  cout << ans << '\n';
}