#undef __GLIBCXX_DEBUG
// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;
const int MAX = int(2e7);
long long a[MAX + 1];
int C[MAX + 1];
bitset<MAX + 1> ip;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<int> ps;
  ps.reserve(1270607);
  for (int i = 2; i <= MAX; ++i) {
    if (!ip[i]) {
      ps.push_back(i);
      for (int j = i * 2; j <= MAX; j += i) {
        ip[j] = false;
      }
    }
  }

  debug(clock());

  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    C[A[i]] += 1;
  }
  
  for (auto p : ps) {
    for (int i = MAX / p; i > 0; --i) {
      C[i] += C[i * p];
    }
  }

  debug(clock());
  for (int i = MAX; i > 0; --i) {
    for (auto p : ps) {
      int x = p * i;
      if (x > MAX) {
        break;
      }
      a[i] = max(a[i], a[x] + (C[i] - C[x]) * 1LL * i);
    }
  }

  cout << a[1] << '\n';
  debug(clock());
}