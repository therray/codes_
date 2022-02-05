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
    int A, B;
    cin >> A >> B;
    int ans = B - A;
    for (int i = 0; i <= B * 2; ++i) {
      ans = min(ans, 1 + i + ((B + i) | A) - (B + i)); 
    }
    cout << ans << '\n';
  }
}