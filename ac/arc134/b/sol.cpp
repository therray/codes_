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
  int N;
  string S;
  cin >> N >> S;
  vector<vector<int>> pos(26);
  for (int i = N - 1; i >= 0; --i) {
    pos[S[i] - 'a'].push_back(i);
  }
  int p = 0;       
  int lr = N;
  for (int i = 0; i < 26; ++i) {
    for (auto r : pos[i]) {
      while (p < N && S[p] <= 'a' + i) {
        ++p;
      }  
      if (p == N || r < p) {
        break;
      }
      if (lr > r) {
        swap(S[p], S[r]);
        ++p;
        lr = r;
      }
    }
  }
  cout << S << '\n';
}