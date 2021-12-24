//author: erray
#include<bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ofstream cc("int");
  int N = rng() % int(2e5) + 1;
  int Q = rng() % int(2e5) + 1;
  cc << N << ' ' << Q << '\n';
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    A[i] = rng() % N + 1;
    cc << A[i] << ' ';
  }
  cc << '\n';

  vector<int> L(Q), R(Q);
  for (int i = 0; i < Q; ++i) {
    int l = rng() % N + 1;
    int r = rng() % N + 1;
    if (l > r) {
      swap(l, r);
    }   
    L[i] = l - 1;
    R[i] = r - 1;
    cc << l << ' ' << r << '\n';
  }

  cc.close();
  system("sol <int >out");
  /*
  ifstream sol("out");
  for (int i = 0; i < Q; ++i) {
    long long resp;
    sol >> resp;
    long long res = 0;
    for (int j = L[i]; j <= R[i]; ++j) {
      for (int k = j + 1; k <= R[i]; ++k) {
        if (A[j] != A[k]) {
          res += (R[i] - k + 1);
        }
      }
    }
    assert(resp == res); 
  }
  sol.close();
  */
}