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
  vector<int> R(N);
  for (int i = 0; i < N; ++i) {
    cin >> R[i];
  }
  vector<int> C(N);
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    cout << (C[Y] > (N - R[X]) ? '#' : '.');
  }
}