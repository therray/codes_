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
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }

    auto Can = [&](int x) {
      auto store = A;
      bool ok = true;
      for (int i = 2; i < N; ++i) {
        
      }
      A = store;
      return ok && (*min_element(A.begin(), A.end()) >= x);
    };

    int low = 0, high = int(1e9);
    while (low < high) {
      int mid = 1 + ((low + high) >> 1);
      if (Can(mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    cout << low << '\n';
  }
}