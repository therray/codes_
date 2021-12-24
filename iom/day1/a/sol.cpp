//author erray
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<int> A(7);
  for (int i = 0; i < 7; ++i) {
    cin >> A[i];
  }

  int x = 4;
  int ans = 0;
  for (int i = 0; i < 365; ++i) {
    ans += A[(4 + i) % 7];
  }
  cout << ans << '\n';
}