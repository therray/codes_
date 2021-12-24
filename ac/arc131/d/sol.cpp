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
  int N, M, D;
  cin >> N >> M >> D;
  vector<long long> R(M);
  { int foo; cin >> foo; }
  for (int i = 0; i < M; ++i) {
    cin >> R[i];
  }
  vector<long long> S(M);
  for (int i = 0; i < M; ++i) {
    cin >> S[i];
  }
  
  vector<pair<long long, long long>> A;
  A.emplace_back(0, 0);
  for (int i = 0; i < M; ++i) {
    A.emplace_back(-R[M - i - 1], S[M - i - 1]);
  }

  for (int i = 0; i < M; ++i) {
    A.emplace_back(R[i] + 1, (i == M - 1 ? 0 : S[i + 1]));
  }

  debug(A);
  long long pos = -1LL * (N / 2) * D;
  vector<long long> upd(D * 5 + 1);
  int p = 0;
  for (int it = 0; it < N; ++it) {
    debug(pos);
    while (p + 1 < int(A.size()) && A[p + 1].first <= pos) {
      ++p;
    }
    upd[0] += A[p].second;
    debug(p, A[p]);
    int _p = p;
    while (p + 1 < int(A.size()) && A[p + 1].first <= pos + D * 5) {
      ++p;
      debug(p, A[p]);
      upd[A[p].first - pos] += A[p].second - A[p - 1].second;
    }
    p = _p;
    pos += D;  
  }

  debug(upd);
  for (int i = 0; i < D * 5; ++i) {
    upd[i + 1] += upd[i];
  }
  cout << (*max_element(upd.begin(), upd.end())) << '\n';
}