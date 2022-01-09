//author: erray
#include<bits/stdc++.h>

using namespace std;


template<typename A, typename B> string to_string(pair<A, B>);
string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* c) {
  return to_string(string(c));
}

string to_string(bool b) {
  return (b ? "true" : "false");
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
  
template<typename T> string to_string(T v) {
  string res = "{";
  for (auto& e : v) {
    if (int(res.size()) > 1) {
      res += ", ";
    }
    res += to_string(e);
  }
  res += "}";
  return res;
}

template<typename A, typename B> string to_string(pair<A, B> p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}

void debug_out() {
  cerr << endl;
}

template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << "  " << to_string(H);
  debug_out(T...);
}

#ifdef DEBUG 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else 
#define debug(...) void(37)
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
    --H[i];
  }

  vector<int> inv(N);
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      inv[i] += (H[j] < H[i]);
    }
  }
  vector<int> pos(N);
  for (int i = 0; i < N; ++i) {
    pos[H[i]] = i;
  }

  vector<int> dp(N + 1, N * N + 5);
  dp[0] = 0;
  for (int i = 0; i < N; ++i) {
    int cost = 0;
    vector<int> sum(N + 1);
    for (int j = 0; j < N; ++j){ 
      sum[j + 1] = sum[j] + (H[j] >= i);
    }
    debug(sum);
    debug(inv);
    for (int j = i; j < N; ++j) {
      cost += sum[pos[j]] - inv[pos[j]];
      debug(i, j, cost);
      dp[j + 1] = min(dp[i] + cost, dp[j + 1]);  
    }

    for (int j = 0; j < pos[i]; ++j) {
      inv[j] -= 1;
    }
  } 
  debug(dp);
  cout << dp[N] << '\n';
}