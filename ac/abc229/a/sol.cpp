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
  string S1, S2;
  cin >> S1 >> S2;
  S1 += S2;
  cout << (count(S1.begin(), S1.end(), '#') == 2 && S1[0] == S1[3] ? "No" : "Yes") << '\n';
}