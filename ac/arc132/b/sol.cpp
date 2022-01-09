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
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    --P[i];
  }

  int ans = N * 2 + 3;
  {
    int p = 0;
    while (p < N && (P[p] + 1) % N == P[(p + 1) % N]) {
      ++p;
    }
    if (p == N) { 
      int m = (N - P[0]) % N;
      ans = min({ans, m, N - m + 2}); 
    }    
  }
  debug(ans);


  {
    int p = 0;
    while (P[p] != 0) {
      ++p;
    }
    debug(p);
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      ok &= (P[(p + N - i) % N] == i);
    }
    debug(ok);
    if (ok) {
      int m = p + 1;
      ans = min({ans, m + 1, N - m + 1}); 
    }
  }  

  for (int i = 0; i < N; ++i) {
    P[i] = N - 1 - P[i];
  }


  cout << ans << '\n';
}