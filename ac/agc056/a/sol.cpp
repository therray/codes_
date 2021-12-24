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
  vector<string> block(N, string(N, '.'));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      block[i][(i * 3 + j) % N] = '#';
    }
  }

  if (N % 3 != 0) {
    reverse(block.begin(), block.begin() + (N / 3));
    reverse(block.end() - (N / 3), block.end());
  }

  for (auto e : block) {
    cout << e << '\n';
  }
}