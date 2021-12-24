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

  vector<long long> p(N + 1);
  for (int i = 0; i < N; ++i) {
    p[i + 1] = p[i] + A[i];
  }

  auto My_assert = [&](bool x) {
    if (!x) {
      cout << -1 << '\n';
      exit(0);
    }
  };

  debug(p);
  My_assert(p[N] == 0);
  long long sum = accumulate(p.begin(), p.end(), 0LL);
  My_assert(sum % N == 0);
  for (int i = 0; i < N; ++i) {
    p[i] -= sum / N;
  }
  debug(p);

  vector<long long> a(N);
  for (int i = 0; i < N - 1; ++i) {
    a[i + 1] = a[i] + p[i];  
  }
  debug(a);

  cout << accumulate(a.begin(), a.end(), 0LL) - N * min(0LL, *min_element(a.begin(), a.end()));

}
