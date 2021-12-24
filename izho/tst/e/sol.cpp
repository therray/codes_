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

  vector<int> pos;
  pos.push_back(-1);
  for (int i = 0; i < N; ++i) {
    if (A[i] == 0) {
      pos.push_back(i);
    }
  }
  pos.push_back(N);
  long long ans = 0;
  vector<int> e(N);
  for (int i = 1; i < int(pos.size()) - 1; ++i) {
    
  }
  
}