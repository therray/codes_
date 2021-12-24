// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

#define EPS 0.0000001

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M, S;
  cin >> N >> M >> S;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  reverse(A.begin(), A.end());
  long double ans = 0;
  
  for (int i = 0; i <= N; ++i) {
    if (1LL * i * M > S) {
      continue;
    }

    long long sum = 0;
    for (int j = 0; j < i; ++j) {
      sum += A[j];
    }   

    long long left = S - i * M;
    long double mans = 1LL * sum * M;
    long double best = 0;
    debug(i, sum, mans, left);
    sum = 0;
    for (int j = i; j < N; ++j) {
      sum += A[j];
      long double res = min((long double) M, (long double) left / (j - i + 1)) * sum;
      if (res - best > EPS) {
        best = res;
      }
    }
    debug(best);
    mans += best;
    if (mans - ans > EPS) {
      ans = mans;
    }
  }
               
  cout << fixed << setprecision(10) << ans << '\n';
}            