//author: erray
#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> string to_string(pair<A, B>);
string to_string(string s) {
  return '"' + s + '"';
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(const char* c) {
  return to_string(string(c));
}

template<size_t T> string to_string(bitset<T> bs) {
  return bs.to_string();
}

string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < int(v.size()); ++i) {
    if (int(res.size()) > 1) {
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

struct DSU {
  vector<int> par;
  DSU(int n) {
    par.resize(n);
    iota(par.begin(), par.end(), 0);
  }
  int get(int x) {
    return par[x] = (par[x] == x ? x : get(par[x]));
  }
  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    par[x] = y;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<array<int, 3>> E(M);
  for (int i = 0; i < M; ++i) {
    cin >> E[i][0] >> E[i][1];
    --E[i][0], --E[i][1];
  }
  vector<string> S(N);
  
  for (int i = 0; i < N; ++i) {
    cin >> S[i]; 
  }
  
  for (int it = 0; it < M; ++it) { 
    int v = E[it][0];
    int u = E[it][1];
    int& c = E[it][2];
    int n = int(S[v].size());
    int m = int(S[u].size());
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, n + m));
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        bool next_i = (i + 1 <= n);
        bool next_j = (j + 1 <= m);
        if (next_i) {
         dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
        }
        if (next_j) {
          dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
        }
        if (next_i && next_j) {
          dp[i + 1][j + 1] = min(dp[i][j] + (S[v][i] != S[u][j]), dp[i + 1][j + 1]);
        }
      }
    }
    debug(v, u, dp);
    c = dp[n][m];
  }
  sort(E.begin(), E.end(), [&](array<int, 3> x, array<int, 3> y) {
    return x[2] < y[2];
  });
  
  DSU d(N);
  int ans = 0;
  for (auto e : E) {
    if (d.unite(e[0], e[1])) {
     ans += e[2];
    }
  }
  cout << ans <<'\n';
}
