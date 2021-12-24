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
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  A.push_back(A[0]);
  A.push_back(A[0]);
  int x = A[1] - A[0];
  if (int(A.size()) < 6 && abs(A[2] - A[1]) == x) {
    cout << "Evet\n" << x + (x == 0) << '\n';
  } else {
    cout << "Yok\n";
  }
}