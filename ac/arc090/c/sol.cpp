// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  int sumB = accumulate(b.begin(), b.end(), 0);
  int sumA = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    sumA += a[i];
    ans = max(ans, sumA + sumB);
    sumB -= b[i];
  }

  cout << ans << '\n';
}