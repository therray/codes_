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
  int H, W, n;
  cin >> H >> W >> n;
  vector<int> R(n), C(n), A(n);
  for (int i = 0; i < n; ++i) {
    cin >> R[i] >> C[i] >> A[i];
    --R[i], --C[i];
  }

  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) {
    return A[x] > A[y];
  });
  vector<int> Rmx(H, -1);
  vector<int> Cmx(W, -1);
  vector<int> ans(n);
  int lst = 0;
  for (int i = 0; i < n; ++i) {
    int x = ord[i];
    ans[x] = max(Rmx[R[x]] + 1, Cmx[C[x]] + 1);
    if (i < n - 1 && A[x] != A[ord[i + 1]]) {
      while (lst <= i) {
        x = ord[lst];
        Rmx[R[x]] = max(Rmx[R[x]], ans[x]);
        Cmx[C[x]] = max(Cmx[C[x]], ans[x]);
        lst += 1;
      }
      lst = i;
    }
  }

  for (auto e : ans) {
    cout << e << '\n';
  }
}