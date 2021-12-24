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
  cin >> s;
  int n = int(s.size());
  int ans = n;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1]) {
      ans = min(ans, max(i + 1, n - i - 1)); 
    }
  }
  cout << ans << '\n';
}