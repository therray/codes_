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
  sort(s.begin(), s.end());
  if (s[0] == s[2]) {
    cout << 1;
  } else if (s[1] == s[0] || s[1] == s[2]) {
    cout << 3;
  } else {
    cout << 6;
  }
}