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
  int K, N;
  cin >> N >> K;
  vector<array<int, 2>> A(N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      int X;
      cin >> X;
      A[i][0] += X;
    }
    A[i][1] = i;
  }

  sort(A.begin(), A.end());
  debug(A);
  int p2 = 0;
  vector<bool> ans(N);
  for (int i = 0; i < N; ++i) {
    while (p2 + 1 < N && A[i][0] + 300 >= A[p2 + 1][0]) {
      ++p2;
    }

    ans[A[i][1]] = (N - p2) <= K;
  }

  for (int i = 0; i < N; ++i) {
    cout << (ans[i] ? "Yes" : "No") << '\n';
  }
}