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
  int N = (1 << 20);
  vector<long long> a(N, -1);
  set<int> act;
  for (int i = 0; i < N; ++i) {
    act.insert(i);
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int T;
    long long X;
    cin >> T >> X;
    int H = (X - 1) % N;
    if (T == 1) {
      auto it = act.lower_bound(H);
      if (it == act.end()) {
        it = act.begin();
      }
      a[*it] = X;
      act.erase(it);
    } else {
      cout << a[H] << '\n';
    }
  }
}