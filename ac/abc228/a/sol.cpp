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
  int S, T, X;
  cin >> S >> T >> X;
  bool ans = false;
  if (S <= T) {
    ans = (X >= S && X < T);
  } else {
    ans = (X >= S || X < T);
  }
  cout << (ans ? "Yes" : "No") << '\n';
}