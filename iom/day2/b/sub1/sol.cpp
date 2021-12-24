//author: erray
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M, P;
  cin >> N >> M >> P;
  if (N <= 5 && M <= 5) {
    vector<vector<int>> ct(N, vector<int>(N));
    for (int i = 0; i < M; ++i) {
      int X, Y;
      cin >> X >> Y;
      --X, --Y;
      ct[X][Y] += 1;
      ct[Y][X] += 1;
    }
    set<vector<vector<int>>> vis;
    queue<vector<vector<int>>> que;
    for (int i = 0; i < int(que.size()); ++i) {
      int sum = 0;
    }
  } else {
    
  }
}