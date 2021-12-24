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
  vector<int> mob(N + 1);
  mob[1] = 1;
  vector<long long> all;
  for (int i = 1; i <= N; ++i) {
    if (mob[i] != 0) {
      all.push_back(i);
      for (int j = i * 2; j <= N; j += i) {
        mob[j] -= mob[i];
      }
    }
  }
  cerr << int(all.size()) << '\n';


}