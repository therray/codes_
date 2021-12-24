// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i][0] >> a[i][1];
      --a[i][0], --a[i][1];
    }
    vector<vector<int>> bs(n);
    for (int i = 0; i < n; ++i) {
      bs[a[i][0]].push_back(a[i][1]);
    }

    vector<int> ct_one(n);
    vector<long long> ct_two(n);
    long long in = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      for (auto e : bs[i]) {
           
      }

      in += int(bs[i].size());
    }
    cout << ans <<' \n';
  }
}