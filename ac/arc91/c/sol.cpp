// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
  }
  if (n == 1) {
    if (m == 1) {
      cout << 1 << ' ';
    } else {
      cout << m - 2 << '\n';
    }
  } else {
    cout << 1LL * n * m - 2LL * (n + m) + 4 << '\n';
  }
}