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
  vector<int> all;
  while (N > 0) {
    int p = 1;
    while (p * (p + 1) / 2 <= N) {
      ++p;
    }
    --p;
    all.push_back(p);
    N -= p * (p + 1) / 2;
  }

  debug(all);
  int lst = 0;
  for (int i = 0; i < int(all.size()); ++i) {
    int p = 1;
    for (int i = 0; i <= all[i] + 1; ++i) {
      p = (p * 10) % 7;
    }
    
    cout << char('1' + (p == 4));
    cout << string(all[2], '7');
  }
}