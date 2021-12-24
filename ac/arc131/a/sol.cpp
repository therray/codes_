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
  string A, B;
  cin >> A >> B;
  cout << A;
  string res;
  bool carry = false;
  for (int i = 0; i < int(B.size()); ++i) {
    cout << ((B[i] - '0') + (carry * 10)) / 2; 
    carry = (B[i] - '0') % 2;
  }

  if (carry) {
    cout << 5;
  }
}