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
  vector<array<int, 2>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i][0] >> a[i][1];
  }

  auto Slope = [&](int x, int y) {
    int X = a[x][0] - a[y][0];
    int Y = a[x][1] - a[y][1];
    int G = gcd(X, Y);
    if (X < 0 && Y < 0) {
      X *= -1;
      Y *= -1;
    }
    return pair{X / G, Y / G}; 
  };

  vector<vector<pair<int, int>>> s(n, vector<pair<int, int>>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        s[i][j] = Slope(i, j);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        ans += (s[i][j] != s[i][k] && s[j][k] != s[j][i]);
      }
    }
  }

  cout << ans << '\n';
}