// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string mx = s, mn = s;
  for (int i = 0; i < int(s.size()); ++i) {
    s += s[0];
    s.erase(s.begin());
    mx = max(mx, s);
    mn = min(mn, s);
  }
  cout << mn << '\n' << mx << '\n';
}