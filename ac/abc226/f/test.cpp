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
  int n;
  cin >> n;
  set<pair<int, long long>> st;
  st.insert({0, 1});
  for (int i = 1; i <= n; ++i) {
    for (auto[c, r] : st) {
      if (c + i > n) {
        break;
      }
      long long x = lcm(i, r);
      for (int j = 1; j * i + c <= n; ++j) {
        st.insert({c + i * j, x});      
      }

    }
  }

  cout << int(st.size()) << '\n';
}