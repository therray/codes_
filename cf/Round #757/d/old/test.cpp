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
  vector<int> a(N + 1);
  iota(a.begin(), a.end(), 0);
  for (int i = N; i > 0; --i) {
    for (int j = i * 2; j <= N; j += i) {
      a[i] = max(a[i], a[j] + 1);
    }
  } 
  cerr << clock() << '\n';
}