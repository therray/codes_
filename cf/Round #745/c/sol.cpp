// author: erray
#pragma GCC optimize ("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> X(n), Y(n);
	for (int i = 0; i < n; ++i) {
	  cin >> X[i] >> Y[i];
	}

  const int SQ = int(sqrt(m)) * 2;
  vector<bool> act(n);
  vector<int> next(n, -1);
  vector<vector<int>> small(SQ, vector<int>(SQ));
  vector<vector<int>> upd(m);
  int bigs = 0;
  for (int t = 0; t < m; ++t) {
    int op, id;
    cin >> op >> id;
    --id;
    op = 2 - op;
    int size = X[id] + Y[id];
    if (size < SQ) {
      if (op) {
        next[id] = t;
      }
      for (int i = X[id]; i < size; ++i) {
        small[size][(next[id] + i) % size] += (op ? 1 : -1);
      }
    } else {
      if (op) {
        int go = t + X[id];
        if (go < m) {
          upd[go].push_back(id);
          next[id] = go;  
        }
      } else {
        bigs -= act[id];
        next[id] = -1;
      } 
      act[id] = false;
    }

    for (auto i : upd[t]) {
      if (next[i] != t) {
        continue;
      }

      int go = t + (act[i] ? X : Y)[i];
      bigs += (act[i] ? -1 : 1);
      if (go < m) {
        next[i] = go;
        upd[go].push_back(i);  
      } 
      act[i] = !act[i];
    }
    upd[t].clear();
    int smalls = 0;
    for (int i = 1; i < SQ; ++i) {
      smalls += small[i][t % i];
    }
    cout << bigs + smalls << '\n';
  }
}