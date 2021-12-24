// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b - 1 > n || 1LL * a * b < n) {
    cout << -1 << '\n';
    return 0;
  }
  
  int last = 0;
  for (int i = n - a; i < n; ++i) {
    cout << i + 1 << ' ';
  }

  last = n - a;
  for (int i = 0; i < b - 1; ++i) {
    int cur = 0;
    while ((cur + 1) <= a && last > 0 && ((i == b - 2) || ((last - 1) / (b - 2 - i) > 0))) {
      ++cur;
      --last;
    }
    for (int j = 0; j < cur; ++j) {
      cout << last + j + 1 << ' ';
    }
  }
  assert(last == 0);
}