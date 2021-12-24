// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << 20 << '\n';
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < int(4e5); ++j) {
      cout << (i % 2 ? ')' : '(');
    }
    cout << '\n';
  }
}