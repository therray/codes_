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
  long long L;
  cin >> N >> L;
  vector<string> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<array<int, 4>> trie;
  array<int, 4> def = {-1, -1, 0, 0};
  trie.push_back(def);
  for (int i = 0; i < N; ++i) {
    int v = 0;
    for (auto c : A[i]) {
      int x = c - '0';
      if (trie[v][x] == -1) {
        trie[v][x] = int(trie.size());
        trie.push_back(def);
        trie.back()[2] = trie[v][2] + 1;
      }
      v = trie[v][x];
    }
    trie[v][3] = true;
  }

  long long ans = 0;
  for (int i = 0; i < int(trie.size()); ++i) {
    long long d = L - trie[i][2]; 
    if (d < 1 || trie[i][3]) {
      continue;
    }
    long long x = 1;
    while (d % (x * 2) == 0) {
      x *= 2;
    }
    for (int j = 0; j < 2; ++j) {
      if (trie[i][j] == -1) {
        ans ^= x;
        debug(x);
      }
    }
  }

  cout << (ans != 0 ? "Alice" : "Bob") << '\n'; 
}