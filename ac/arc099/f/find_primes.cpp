// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = int(1e9); i < int(1e9 + 200); ++i) {
    bool ok = true;
    for (int j = 2; j * j <= i; ++j) {
      ok &= (i % j != 0);
    }
    if (ok) {
      cout << i << ", ";
    }
  }
}