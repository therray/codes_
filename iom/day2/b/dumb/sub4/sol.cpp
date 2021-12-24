//author: erray
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M, P;
  cin >> N >> M >> P;
  vector<vector<int>> G(N);
  bool ok = true;
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
    ok &= (X != Y)
  }

}