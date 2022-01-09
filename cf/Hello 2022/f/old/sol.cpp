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
    cin >> N >> A >> B >> C;
    string S;
    cin >> S;
    vector<int> zr;
    int ones = count(S.begin(), S.end(), '1');
    int used = 0;
    for (int i = 0; i < N; ++i) {
      used += (S[i] == '1');
      if (used && ones != used && S[i] == '0') {
        if (S[i - 1] == '1') {
          zr.push_back(0);
        }
        zr.back() += 1;
      }
    }
    sort(zr.begin(), zr.end());
    vector<int> nons;
    {
      int p = 0;
      while (S[p] == '0') {
        ++p;
      }
      if (p != 0) {
        nons.push_back(p);
      }
    }

    {
      int p = N - 1;
      while (S[p] == '0') {
        --p;
      }
      if (p != N - 1) {
        nons.push_back(N - 1 - p);
      }
    }

    vector<pair<int, bool>> events;
    for (auto e : zr) {
      events.emplace_back(e, true);
    }
    for (auto e : nons) {
      events.emplace_back(e, false);
    }
    array<int, 2> ct = {};
    for (int i = 1; i < N; ++i) {
      if (S[i] == S[i - 1]) {
        ct[S[i] - '0'] += 1;
      }
    }

    debug(events);
    debug(ct);
    int p = 0;
    int take = 0;
    while (p < int(events.size()) && events[p].first == 1) {
      take += events[p].second;
      ++p;
    }
    debug(take);
    long long ans = 0;
    {
      int nns = 0;
      for (auto e : nons) {
        if (e == 1) {
          nns += 1;
        }
      }
      nns = min(nns, ct[1] - i + 1);
      ans = max(ans, !!ct[1] * B + max(0LL, 1LL * (take + nns) * (B - C)) + ((*max_element(events.begin(), events.end())).first > 1) * A);    
    }
    debug(ans);
    for (int i = 1; i <= min(ct[1] + 1, ct[0]); ++i) {
      debug(i, p, events);
      --events[p].first;
      while (p < int(events.size()) && events[p].first == 1) {
        take += events[p].second;
        ++p;
      }    
      int nns = 0;
      for (auto e : nons) {
        if (e == 1) {
          nns += 1;
        }
      }
      nns = min(nns, ct[1] - i + 1);
      ans = max(ans, max(0LL, 1LL * take * (B - C)) + 1LL * i * A + 1LL * (i - 1) * B + max(0LL, 1LL * nns * (B - C)));
    }
    cout << ans << '\n';
  }
}