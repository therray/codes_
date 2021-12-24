// author: erray
#include <bits/stdc++.h>
 
using namespace std;


mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count()); 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n = rng() % 1000 + 2;
  int m = rng() % n + n;
  cout << n << ' ' << m << ' ' << 1 << '\n';
  while (m--) {
    int x = rng() % n + 1;
    int y;
    do 
    y = rng() % n + 1;
    while (x == y);

    cout << min(x, y) << ' ' << max(x, y) << '\n'; 
  }

  cout << rng() % n + 1 << '\n';
  int s = rng() % (n / 2);
  cout << s << '\n';
  for (int i = 0; i < s; ++i) {
    cout << rng() % n + 1 << ' ';
  }
}