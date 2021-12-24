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
  long long L, R;
  cin >> N >> L >> R;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  //abs(sum - R - L + A - B) <= R - L
  long long start = accumulate(A.begin(), A.end(), 0LL) - R - L;
  long long ans = R - L + 1;
  sort(A.begin(), A.end());
  for (int i = 0; i < N; ++i) {
    auto store = A;
    A.erase(A.begin() + i);
    A.insert(lower_bound(A.begin(), A.end(), store[i] + start), store[i] + start);
    long long res = 0;
    for (int j = 0; j < N; j += 2) {
      res += A[j + 1] - A[j];
    }
    ans = min(ans, res);
    swap(store, A);
  } 
  cout << (ans <= R - L ? "Alice" : "Bob") << '\n';
}