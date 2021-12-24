// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  vector<int> divsA;
  vector<int> divsB;
  int A = a[0];
  int B = b[0];
  for (int i = 1; i * i <= int(1e9); ++i) {
    if (A % i == 0) {
      divsA.push_back(i);
      divsA.push_back(A / i);
    }

    if (B % i == 0) {
      divsB.push_back(i);
      divsB.push_back(B / i);
    }  
  }

  long long ans = 0;
  for (auto f : divsA) {
    for (auto s : divsB) {
      bool ok = true;
      for (int i = 0; i < n; ++i) {
        ok &= (a[i] % f == 0 && b[i] % s == 0) || (b[i] % f == 0 && a[i] % s == 0); 
      }
      if (ok) {
        ans = max(ans, 1LL * f / gcd(f, s) * s);
      }
    }
  }
  cout << ans << '\n';
}