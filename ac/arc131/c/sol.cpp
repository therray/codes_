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
  vector<int> A(N);
  int xr = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    xr ^= A[i];
  }

  cout << (N % 2 == 1 || count(A.begin(), A.end(), xr) ? "Win" : "Lose") << '\n';
}