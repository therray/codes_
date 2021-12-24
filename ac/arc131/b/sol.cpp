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
  int N, M;
  cin >> N >> M;
  vector<string> C(N);
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }

  const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
  auto G = [&](int x, int y) {
    if (C[x][y] != '.') {
      return C[x][y];
    }
    vector<bool> ok(5, true);
    for (int d = 0; d < 4; ++d) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx >= 0 && nx < N && ny >= 0 && ny < M && C[nx][ny] != '.') {
        debug(C[nx][ny]);
        ok[C[nx][ny] - '1'] = false;
      }
    }

    int p = 0;
    while (!ok[p]) {
      ++p;
    }
    return char('1' + p);
  };

  for (int b = 0; b < 2; ++b) {
    for (int i = 0; i < N; ++i) {
      for (int j = (i % 2) ^ b; j < M; j += 2) {
        C[i][j] = G(i, j);
      }
    }
  }
  for (auto e : C) {
    cout << e << '\n';
  }
}