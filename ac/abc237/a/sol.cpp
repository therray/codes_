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
  long long X;
  cin >> X;
  long long t = 1LL << 31;
  cout << (X >= -t && X <= t - 1 ? "Yes" : "No") << '\n';
}