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
  vector<int> freq(N);
  for (int i = 0; i < N; ++i) {
    int X;
    cin >> X;
    --X;
    freq[X] += 1;
  }
  sort(freq.rbegin(), freq.rend());
  int ans = N;
  for (int i = 0; i < K; ++i) {
    ans -= freq[i];
  }
  cout << ans << '\n';
}