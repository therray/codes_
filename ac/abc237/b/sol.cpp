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
  string S;
  cin >> N >> S;
  vector<int> L(N + 1, -1), R(N + 1, -1);
  for (int i = 0; i < N; ++i) {
    (S[i] == 'L' ? L : R)[i] = i + 1;
  }
  function<void(int)> Dfs = [&](int v) {
    if (v == -1) {
      return;
    }
    Dfs(L[v]);
    cout << v << ' ';
    Dfs(R[v]);
  };
  Dfs(0);
}