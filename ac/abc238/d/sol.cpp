// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    long long a, s;
    cin >> a >> s;
    s -= a * 2;
    cout << (s < 0 || (s & a) != 0 ? "No" : "Yes") << '\n';
  }
}