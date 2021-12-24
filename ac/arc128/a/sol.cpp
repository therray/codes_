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
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<int> pos(N, -1);
  for (int i = 0, p = 0; i < N; ++i) {
    if (i == 0 || A[i] != A[i - 1]) {
      pos[p++] = i;
    }
  }
  A.erase(unique(A.begin(), A.end()), A.end());
  vector<bool> ans(N);
  bool prev = true;
  for (int i = 0; i < int(A.size()); ++i) {
    int mn = int(1e9);
    int mx = 1;
    for (auto add : {1, -1}) {
      if (i + add >= 0 && i + add < int(A.size())) {
        mn = min(mn, A[i + add]);
        mx = max(mx, A[i + add]);
      }
    }
    if (mx < A[i]) {
      ans[pos[i]] = prev;
    } else if (mn > A[i]) {
      ans[pos[i]] = !prev;
    }
    if (ans[pos[i]]) {
      prev ^= 1;
    }
  }

  if (count(ans.begin(), ans.end(), 1) % 2 == 1) {
    int p = N - 1;
    while (!ans[p]) {
      --p;
    }
    ans[p] = false;
  }

  for (auto e : ans) {
    cout << int(e) << ' ';
  }
}