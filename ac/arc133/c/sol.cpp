// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int H, W, K;
  cin >> H >> W >> K;
  vector<int> A(H);
  for (int i = 0; i < H; ++i) {
    cin >> A[i];
  }
  vector<int> B(W);
  for (int i = 0; i < W; ++i) {
    cin >> B[i];
  }

  int sum = 0;
  for (auto e : A) {
    sum = (sum + e) % K;
  }
  for (auto e : B) {
    sum = (sum - e) % K;
  }
  if (sum != 0) {
    cout << -1 << '\n';
    return 0;
  }
  
  long long aans = 0;
  for (auto e : A) {
    int me = (1LL * W * (K - 1)) % K;
    if (e <= me) {
      aans += me - e;
    } else {
      aans += me + (K - e);
    }
  }

  long long bans = 0;
  for (auto e : B) {
    int me = (1LL * H * (K - 1)) % K;
    if (e <= me) {
      bans += me - e;  
    } else {
      bans += me + (K - e);
    }
  }
  cout << 1LL * (K - 1) * H * W - max(aans, bans) << '\n'; 
}