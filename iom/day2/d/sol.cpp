//author: erray
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT, G;
  cin >> TT >> G;
  const int MAX = int(1e6);
  vector<int> mn(MAX + 1, -1);
  for (int i = MAX - 1; i >= 0; --i) {
    for (int j = 1; j > 0; --j) {
      long long d = i * (i + j);
      long long s = 
      while (mn[d] != -1) {
        mn[d] = i * 2 + j + (d - s);
      } 
    } 
  }

  if (G == 1) {
    while (TT--) {
      int N, A;
      cin >> N >> A;
      cout << (mn[N] >= A ? 1 : -1) << '\n';
    }
  }
}