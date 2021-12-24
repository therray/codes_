// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      mat[i][j] = (c - '0');
    }
  }
  
  vector<vector<int>> pref(n + 1, vector<int>(m + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 && j == 0) {
        pref[i + 1][j + 1] = mat[i][j];
      } else if (i == 0) {
        pref[i + 1][j + 1] = mat[i][j] + pref[i + 1][j];
      } else if (j == 0) {
        pref[i + 1][j + 1] = mat[i][j] + pref[i][j + 1];
      } else {
        pref[i + 1][j + 1] = mat[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
      }
    }
  }

  int ans = 0;
  for (int sx = 0; sx <= n; ++sx) {
    for (int sy = 0; sy <= m; ++sy) {
      for (int ex = sx + 1; ex <= n; ++ex) {
        for (int ey = sy + 1; ey <= m; ++ey) {
          int sum = pref[ex][ey] - pref[sx][ey] - pref[ex][sy] + pref[sx][sy];
          if (sum == 0) {
            ans = max(ans, ex - sx + ey - sy); 
          }
        }
      }
    }
  }               
  cout << ans * 2 << '\n';
}