// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  for (int i = k + 1; i <= n; ++i) {
    for (int j = 0; j <= n; j += i) {
      int r = (min(i + j - 1, n)) % i;
      ans += max(0, r - k + 1);
    }
  }
  cout << ans - (k == 0 ? n : 0) << '\n';
}