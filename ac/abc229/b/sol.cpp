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
  string A, B;
  cin >> A >> B;
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  bool ok = false;
  for (int i = 0; i < min(int(A.size()), int(B.size())); ++i) {
    ok |= (A[i] + B[i] - '0' * 2) >= 10;
  }
  cout << (ok ? "Hard" : "Easy") << '\n';
}