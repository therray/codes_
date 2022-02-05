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
  int N;
  cin >> N;
  vector<bool> mark(360);
  int cur = 0;
  for (int i = 0; i < N; ++i) {
    int X;
    cin >> X;
    (cur += X) %= 360;
    mark[cur] = true;
  }
  mark[0] = true;
  int l = 0;
  int ans = 0;
  for (int i = 1; i < 360; ++i) {
    if (mark[i]) {
      ans = max(ans, i - l);
      l = i;
    }
  }
  cout << max(ans, 360 - l) << '\n';
}