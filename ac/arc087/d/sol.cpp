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
  string s;
  int X, Y;
  cin >> s >> X >> Y;
  int n = int(s.size());
  bool c = false;
  const int MAX = 8000 + 1;
  array<bitset<MAX>, 2> can = {};
  can[0][0] = true;
  can[1][0] = true;
  int sum = 0;
  bool first = true;
  for (int i = 0; i <= n; ++i) {
    if (i == n || s[i] == 'T') {
      if (!first) {
        can[c] = (can[c] << sum) | (can[c] >> sum);       
      } else {
        X -= sum;
        first = false;
      }
      c ^= 1;
      sum = 0;
    } else {
      sum += 1;
    } 
  }
  cout << (can[0][abs(X)] && can[1][abs(Y)] ? "Yes" : "No") << '\n';
}