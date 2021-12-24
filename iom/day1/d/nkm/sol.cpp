#pragma C("-Wall");
//author erray
#include<bits/stdc++.h>

using namespace std;


template<typename A, typename B> string to_string(pair<A, B>);
template<typename A, typename B, typename C> string to_string(tuple<A, B, C>);
string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* c) {
  return to_string(string(c));
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
string to_string(char c) {
  return "'"s + c + "'";
}
template<size_t T> string to_string(bitset<T> bs) {
  return bs.to_string();
}
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < int(v.size()); ++i) {
    if (i > 0) {
      res += ", ";
    }
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template<typename T> string to_string(const T& x) {
  string res = "{";
  for (auto& e : x) {
    if (int(res.size()) > 1) {
      res += ", ";
    }
    res += to_string(e);
  }
  res += "}";
  return res;
}
void debug_out() {
  cerr << endl;
}
template<typename H, typename... T> void debug_out(H head, T... tail) {
  cerr << "  " << to_string(head);
  debug_out(tail...);
}
#ifdef DEBUG 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) void(37)
#endif


int dp[1 << 19];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<vector<array<int, 2>>> A(N);
  for (int i = 0; i < N; ++i) {
    int K;
    cin >> K;
    A[i].resize(K);
    for (int j = 0; j < K; ++j) {
      cin >> A[i][j][0] >> A[i][j][1];
    }
    sort(A[i].rbegin(), A[i].rend());
    vector<array<int, 2>> c;
    int mx = -1;
    for (int j = 0; j < K; ++j) {
      if (mx < A[i][j][1]) {
        mx = A[i][j][1];
        c.push_back(A[i][j]);
      }
    }
    swap(A[i], c);
  }

  vector<int> ord(N);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y)  {
    return int(A[x].size()) > int(A[y].size());
  });
  int s = 1;
  dp[0] = 0;
  for (auto& id : ord) {
    auto& e = A[id];
    for (int i = s - 1; i >= 0; --i) {
      for (auto&[x, y] : e) {
        dp[i + x] = max(dp[i + x], dp[i] + y);     
      } 
    }
    s += e[0][0];
  }

  int ans = 0;
  for (int i = 0; i < s; ++i) {
    ans = max(ans, min(i, dp[i]));
  }
  cout << ans << '\n';
}