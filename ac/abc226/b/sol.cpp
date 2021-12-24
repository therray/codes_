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
  vector<set<vector<int>>> all(int(2e5) + 1);
  for (int i = 0; i < N; ++i) {
    int L;
    cin >> L;
    vector<int> A(L);
    for (int j = 0; j < L; ++j) {
      cin >> A[j];
    }
    all[L].insert(A);
  }

  int ans = 0;
  for (auto e : all) {
    ans += int(e.size());
  }
  cout << ans << '\n';
}