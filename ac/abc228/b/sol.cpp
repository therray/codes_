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
  int N, X;
  cin >> N >> X;
  --X;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    --A[i];
  }

  queue<int> que;
  que.push(X);
  vector<bool> vis(N);
  vis[X] = true;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    if (!vis[A[v]]) {
      vis[A[v]] = true;
      que.push(A[v]);
    }
  }
  cout << accumulate(vis.begin(), vis.end(), 0) << '\n';
}