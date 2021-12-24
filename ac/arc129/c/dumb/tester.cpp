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
  ofstream out("int");
  out << N;
  out.close();
  system("sol <int >out");
  ifstream in("out");
  string s;
  in >> s;
  in.close();
  reverse(s.begin(), s.end());
  int ans = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    int c = 1;
    int tot = 0;
    for (int j = i; j < int(s.size()); ++j) {
      (tot += (s[j] - '0') * c) %= 7;
      (c *= 10) %= 7;
      ans += (tot == 0);
    }
  }

  assert(ans == N);
}