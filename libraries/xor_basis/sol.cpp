// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
template<typename T> struct XorBasis {
  vector<T> a;
  int n;
  XorBasis(int _n) : n(_n) {
    a.resize(n, 0);
  } 

  bool insert(T x, bool keep = true) {
    for (int i = n - 1; i >= 0; --i) {
      if (~(x >> i) & 1) {
        continue;
      } 
      x ^= a[i];
      if (a[i] == 0) {
        if (keep) {
          a[i] = x;
        }
        return true;
      }
    }
    return false;
  }

  bool can(T x) {
    return !insert(x, false);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
}