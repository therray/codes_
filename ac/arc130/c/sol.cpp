// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string A, B;
  cin >> A >> B;
  bool swapped = false;
  if (int(A.size()) < int(B.size())) {
    swapped = true;
    swap(A, B);  
  }

  sort(A.begin(), A.end());
  sort(B.rbegin(), B.rend());
  while (int(B.size()) < int(A.size())) {
    B += '0';
  }
  
  auto Print = [&] {
    while (B.back() == '0') {
      B.pop_back();
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    if (swapped) {
      swap(A, B);
    }
    cout << A << '\n';
    cout << B << '\n';
    exit(0);
  };

  if (A.back() + B.front() - 2 * '0' < 10) {
    Print();
  }

  int p = 0;
  vector<int> ind(int(A.size()), -1);
  int bigger = -1;
  for (int i = 0; i < int(B.size()); ++i) {
    while (p < int(A.size()) && B[i] + A[p] - 2 * '0' < 9) {
      ++p;
    }
    if (p < int(A.size())) {
      ind[p] = i;
      if (B[i] + A[p] - 2 * '0' > 9) {
        bigger = i;
      }
      ++p;
    }
  }
  debug(ind);

  string res_A;
  for (int i = 0; i < int(A.size()); ++i) {
    if (ind[i] != -1) {
      res_A += A[i];
    }
  }

  for (int i = 0; i < int(A.size()); ++i) {
    if (ind[i] == -1) {
      res_A += A[i];
    }
  }

  swap(res_A, A);
  debug(B, A);      
  debug(bigger);

  if (bigger == -1) {
    int mx = int(A.size()) - 1;
    while (A[mx] + B[0] - 2 * '0' < 10) {
      --mx;
    }
    swap(A[0], A[mx]);
  } else {
    swap(A[0], A[bigger]);
    swap(B[0], B[bigger]);
  }

  Print();
}