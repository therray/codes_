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
  int N;
  cin >> N;
  vector<int> all;
  for (int i = 1; i == 1 || all.back() <= N; ++i) {
    all.push_back(i * (i + 1) / 2);
  }
  all.pop_back();

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    int x = i;
    int res = 0;
    while (x > 0) {
      x -= *prev(lower_bound(all.begin(), all.end(), x + 1));
      res += 1;          
    }
    ans = max(ans, res);
  }
  cout << ans << '\n';
}