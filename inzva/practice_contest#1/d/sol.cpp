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
  array<int, 3> A;
  cin >> A[0] >> A[1] >> A[2];
  sort(A.begin(), A.end());
  cout << A[1] << '\n';
}