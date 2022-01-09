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
  int TT;
  cin >> TT;
  while (TT--) {
    int N, A, B, C;
    string S;
    cin >> N >> A >> B >> C >> S;
    array<int, 2> ct = {};
    for (int i = 0; i < N - 1; ++i) {
      if (S[i] == S[i + 1]) {
        ct[S[i] - '0'] += 1;
      }
    }
    if (count(S.begin(), S.end(), '1') == 0) {
      cout << (N > 1) * A << '\n';
      continue;
    } 
    int first = 0;
    int last = N - 1;
    while (S[first] == '0') {
      ++first;
    }
    while (S[last] == '0') {
      --last;
    }
    vector<int> zs;
    for (int i = first; i <= last; ++i) {
      if (S[i] == '0') {
        if (S[i - 1] == '1') {
          zs.push_back(0);
        }
        zs.back() += 1;
      }
    }
    sort(zs.begin(), zs.end());

    long long ans = 0;
    int c = int(count(S.begin(), S.end(), '1'));
    for (int i = 0; i <= ct[1]; ++i) {
      int cc = min(i + 1, ct[0]);
      if (N - c >= ct[1] - 1) {
        ans = max(ans, 1LL * i * B + 1LL * A * cc - 1LL * max(0, i - 1 - cc) * C);
      }
    }
    debug(ans);
    debug(zs);

    int tot = 0;
    for (int extra = 0; extra < int(zs.size()); ++extra) {
      if (ct[1] + extra - 1 > N - c) {
        break;
      }
      tot += zs[extra];
      int big = tot - (extra + 1);
      int cc = ct[1] + extra + 1;
      int left = cc + 1 - tot;
      int left_big = ct[0] - big;
      int take_big = min(left_big, left);
      debug(extra, big, cc, left, left_big, take_big);
      left -= take_big;
      if (left >= 0 && left_big >= 0) {
        ans = max(ans, 1LL * cc * B - 1LL * (extra + 1) * C + 1LL * (big + take_big) * A - 1LL * max(0, left - 2) * C);
      }
    }

    cout << ans << '\n';
  }
}