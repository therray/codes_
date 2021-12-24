// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (i > 0 && pq.top() < x) {
      ans += x - pq.top();
      pq.pop();
      pq.push(x);
      pq.push(x);
    } else {
      pq.push(x);
    }
  }

  cout << ans << '\n';
}