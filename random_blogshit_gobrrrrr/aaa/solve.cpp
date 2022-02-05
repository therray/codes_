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
  int ans = 0;
  for (int i = 0; i < 10; ++i) {
    char foo;
    int X = 0, Y;
    cin >> foo;
    while (foo != ',') {
      cin >> foo;
      if (foo != ',') {
        X *= 10;        
        X += foo - '0';
      }
    } 
    cin >> Y;
    cout << "(" << X << ", " << Y << "): " << gcd(X, Y) + 1 << '\n';;
    ans += gcd(X, Y) + 1;
  }
}