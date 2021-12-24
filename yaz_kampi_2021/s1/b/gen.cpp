// author: erray
#include <bits/stdc++.h>
 
using namespace std;


mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count()); 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n = rng() % 45 + 1;
  int k = rng() % n + 1;
  cout << n << ' ' << k << '\n';
  vector<int> all(n);
  iota(all.begin(), all.end(), 
}