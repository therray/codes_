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
  for (int i = 0; i < N; ++i) {
    int ind = int(min_element(A.begin() + i, A.end()) - A.begin());
    if (i != ind) {
      ans.emplace_back(i, ind);
      swap(A[i], A[ind]);
    }
  }

  cout << int(ans.size()) << '\n';
  for (auto e : ans) {
    cout << e.first  << ' ' << e.second << '\n';
  }
}