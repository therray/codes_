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
  vector<int> add;
  while (N > 0) {
    int low = 0, high = int(1e3);
    while (low < high) {
      int mid = 1 + ((low + high) >> 1);
      if (mid * (mid + 1) / 2 <= N) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    N -= low * (low + 1) / 2;
    add.push_back(low);
  }

  debug(add);
  assert(int(add.size()) <= 7);
  int b = 1;
  int c = 0;
  string s;
  for (int i = 0; i < int(add.size()); ++i) {
    for (int it = 0; it <= add[i] - (i == 0); ++it) {
      int p = 1;
      while ((c + (p * b)) % 7 != i) {
        ++p;
      }
      s += char('0' + p);
      c = i;
      (b *= 10) %= 7;
    }
  }

  reverse(s.begin(), s.end());
  cout << s << '\n';
}