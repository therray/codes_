//author erray
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  while (int(A.size()) < 3) {
    A.push_back(1);
  }
  N = 3;

  long long _K = K;
  vector<pair<int, long long>> ct;
  for (int i = 2; i * i <= K; ++i) {
    int c = 0;
    while (K % i == 0) {
      ++c;
      K /= i;
    }
    if (c > 0) {
      ct.emplace_back(i, c);
    }
  }

  if (K > 1) {
    ct.emplace_back(K, 1);
  }
  K = _K;
  vector<array<long long, 3>> ns;
  ns.push_back({1, 1, 1});
  for (auto[x, c] : ct) {
    vector<long long> pw(c + 1, 1);
    for (int i = 0; i < c; ++i) {
      pw[i + 1] = pw[i] * x;
    }
    vector<array<long long, 3>> new_ns;   
    for (int i = 0; i <= c; ++i) {
      for (int j = i; j <= c; ++j) {
        int first = i;
        int second = j - i;
        int third = c - j;
        for (auto[x, y, z] : ns) {
          new_ns.push_back({x * pw[first], y * pw[second], z * pw[third]});
        }
      }
    }
    swap(ns, new_ns);
  }

  long long ans = 0;
  for (auto[x, y, z] : ns) {
    if (x <= A[0] && y <= A[1] && z <= A[2]) {
      ans = max(ans, (A[0] / x) * (A[1] / y) * (A[2] / z));
    }
  }
  cout << ans << '\n';
}