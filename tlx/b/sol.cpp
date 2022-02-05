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
  int N, F;
  long long D;
  cin >> N >> F >> D;
  int left = F - N;
  int mx = F + left / 2;

  cout << (N >= F && 1LL * F * (F + 1) / 2 <= D && 1LL * 

}