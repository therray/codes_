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
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  vector<int> ord(N);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](auto x, auto y) {
    return pair{A[x], -B[x]} < pair{A[y], -B[y]};
  });
  
  long long ans = 0;
  function<vector<int>(vector<int>)> Inv = [&](vector<int> x) -> vector<int> {
    if (int(x.size()) <= 1) {
      return x;
    }    
    int size = int(x.size());
    auto L = Inv(vector<int>(x.begin(), x.begin() + (size / 2)));
    auto R = Inv(vector<int>(x.begin() + (size / 2), x.end()));
    vector<int> res;
    res.reserve(size);
    int pl = 0;
    int pr = 0;
    L.push_back(int(1e9) + 1);
    R.push_back(int(1e9) + 1);
    while (pl < int(L.size()) && pr < int(R.size())) {
      if (L[pl] < R[pr]) {
        res.push_back(L[pl]);
        ++pl;
        ans += pr;
      } else {
        res.push_back(R[pr]);
        ++pr;
      }
    }
    return res;
  };
  vector<int> ord_B(N);
  vector<int> ord_A(N);
  for (int i = 0; i < N; ++i) {
    ord_B[i] = B[ord[i]];
    ord_A[i] = A[ord[i]];
  }
  debug(ord_B);
  debug(ord_A);
  Inv(ord_B);
  map<pair<int, int>, int> ct;
  for (int i = 0; i < N; ++i) {
    ans += ct[{A[i], B[i]}]++;
  }
  #ifdef DEBUG 
    long long inv = 0;
    for (int i = 0 ; i < N; ++i) {
      for (int j = 0; j <= i; ++j) {
        inv += ord_B[i] <= ord_B[j];
      }
    }
    debug(inv, ans + N);
  #endif
  cout << ans + N << '\n';
}