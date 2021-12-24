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
  string S, T;
  cin >> S >> T;
  char d = T[0] - S[0];
  for (auto& e : S) {
    e += d;
    if (e < 'a') {
      e = 'z' - ('a' - e - 1);
    } else if (e > 'z') {
      e = 'a' + (e - 'z' - 1);
    }
  }
  cout << (S == T ? "Yes" : "No") << '\n';
}