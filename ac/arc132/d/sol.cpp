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
  int N, M;
  string S, T;
  cin >> N >> M >> S >> T;
  int n = N + M;
  vector<int> posS;
  vector<int> posT;
  for (int i = 0; i < n; ++i) {
    if (S[i] == '0') {
      posS.push_back(i);
    }
    if (T[i] == '0') {
      posT.push_back(i);
    }
  }

  vector<array<int, 2>> ranges;
  for (int i = 0; i < N; ++i) {
    int l = posS[i];
    int r = posT[i];
    if (l > r) {
      swap(l, r);
    }
    ranges.push_back({l, r});
  }
  sort(ranges.begin(), ranges.end());
  //if segments intersect, then l0 <= l1, r0 <= r1
  int ans = n;
  for (auto pos : {-1, n + 1}) {
    string res(n, '0');
    for (auto[l, r] : ranges) {
      l = max(l, pos + 1);
      pos = (l <= r && pos + 1 == l ? pos + 1 : r);
      res[pos] = '1';
    } 

    int mans = 0;
    for (int i = 0; i < n - 1; ++i) {
      mans += (res[i] != res[i + 1]);
    }
    ans = min(ans, mans);
  }
  cout << n - 1 - ans << '\n';

}