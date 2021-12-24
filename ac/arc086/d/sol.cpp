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

  vector<pair<int, int>> ans;
  auto Do = [&](int x, int y) {
    A[y] += A[x];
    ans.emplace_back(x, y);
  };

  int mn = int(min_element(A.begin(), A.end()) - A.begin());
  int mx = int(max_element(A.begin(), A.end()) - A.begin());
  if (abs(A[mn]) >= abs(A[mx])) {
    debug(A[mn]);
    for (int i = 0; i < N; ++i) {
      Do(mn, i); 
    }
    debug(A);
    for (int i = N - 2; i >= 0; --i) {
      if (A[i] > A[i + 1]) {
        Do(i + 1, i);
      }
    } 
  } else {
    for (int i = 0; i < N; ++i) {
      Do(mx, i); 
    }
    debug(A);
    for (int i = 0; i < N - 1; ++i) {
      if (A[i + 1] < A[i]) {
        Do(i, i + 1);
      }
    }
  }

  debug(A);
  cout << int(ans.size()) << '\n';
  for (auto[x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
}