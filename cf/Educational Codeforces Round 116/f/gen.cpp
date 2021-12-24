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
  cout << N << '\n';
  for (int i = 0; i < N - 1; ++i) {
    cout << i + 1 << ' ' << i + 2 << '\n';
  }
  cout << 0 << '\n';
}