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
  int TT;
  cin >> TT;
  while (TT--) {
    array<int, 3> A;
    for (int i = 0; i < 3; ++i) {
      cin >> A[i];
    }

    int ans = int(1e9);
    for (int i = 0; i < 3; ++i) {
      swap(A[0], A[i]);      
      auto store = A;
      int diff = abs(A[1] - A[2]);
      if (diff % 3 != 0) {
        continue;
      }
      int mid = max(A[1], A[2]) - diff / 3;
      ans = min(ans, diff / 3 + mid);
      A = store;
    }

    cout << (ans == int(1e9) ? -1 : ans) << '\n';
  }
}