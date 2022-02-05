// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N * 2);
  for (int i = 0; i < N * 2; ++i) {
    cin >> A[i];
  }

  array<int, 2> mn = {int(1e9), int(1e9)};
  for (int i = 0; i < N; ++i) {
    mn = min(mn, array{A[i], A[i + N]});
  }
  if (mn[1] <= mn[0]) {
    cout << mn[0] << ' ' << mn[1] << '\n';
    return 0;
  }
  vector<int> ord(N);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) {
    return pair{A[x], x} < pair{A[y], y};
  });
  int p = -1;
  int first = -1;
  int next = -1;
  vector<int> ans;
  for (auto i : ord) {
    if (p > i) {
      continue;
    }
    if (first == -1 || (A[i] < first || (A[i] == first && next > first))) {
      ans.push_back(i);
      p = i;
      if (first == -1) {
        first = A[i + N];
      } else if (next == -1 && A[i + N] != first) {
        next = A[i + N];
      }
    }      
  }

  for (auto e : ans) {
    cout << A[e] << ' ';
  }
  for (auto e : ans) {
    cout << A[e + N] << ' ';
  }

}