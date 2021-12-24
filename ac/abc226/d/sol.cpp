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
  vector<int> X(N);
  vector<int> Y(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }

  vector<array<int, 2>> all;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (j != i) {
        int dx = X[i] - X[j];
        int dy = Y[i] - Y[j];
        int g = gcd(dx, dy);
        dx /= g;
        dy /= g;
        all.push_back({dx, dy});
      }  
    }
  }

  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  cout << int(all.size()) << '\n';
}