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
  long long A, B, N;
  cin >> A >> B >> N;
  long long g = gcd(A, B);
  N /= g;
  A /= g;
  B /= g;
  if (B > A) {
    swap(A, B);
  }
  long long till = min(A - 1, N / B);
  
}