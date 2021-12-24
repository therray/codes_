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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    a[i] %= 2;
  }

  array<int, 2> ct = {};
  for (int i = 0; i < n; ++i) {
    ct[i % 2] += 1;
    ct[a[i]] -= 1;
  }

  vector<vector<int>> 
  //this is bs

}