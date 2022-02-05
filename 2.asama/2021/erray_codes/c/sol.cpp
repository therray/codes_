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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M, X;
  cin >> N >> M >> X;
  vector<vector<long long>> A(N, vector<long long>(M));
  vector<long long> R(M);
  vector<long long> pr(M + 1);
  for (int i = 0; i < M; ++i) {
    cin >> R[i];
    pr[i + 1] = pr[i] + R[i];
  }
  
  vector<vector<long long>> pra(N, vector<long long>(M + 1));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> A[i][j];
      pra[i][j + 1] = pra[i][j] + A[i][j];
    }
  }
  debug(R, pr);
  debug(A, pra);
  vector<vector<long long>> ct(M, vector<long long>(X + 1));
  for (int i = 0; i < M; ++i) {
    vector<long long> seg;
    long long l = pr[i];
    long long r = pr[i] + R[i] - 1;
    if (R[i] == 0) {
      continue;
    }
    debug(i, l, r);
    map<long long, int> ends;
    map<long long, int> starts;  
    long long delt = 0;  
    for (int j = 0; j < N; ++j) {
      long long ll = pra[j][i];
      long long rr = pra[j][i] + A[j][i] - 1;
      if (ll <= rr) {
        debug(ll,rr);
        ends[rr] += 1;
        starts[ll] += 1;
        if (ll <= l && l <= rr) {
          delt += 1;
        }
        if (ll <= r + 1 && r + 1 <= rr) {
          delt -= 1;
        } 
        long long ml = max(ll, l);
        long long mr = min(rr, r);
        ct[i][0] += max(0LL, mr - ml + 1);
      }
    }
    debug(starts);
    debug(ends);
    debug(ct[i][0], delt);
    for (int j = 1; j <= X; ++j) {
      --l, --r;      
      delt -= starts[l + 1];
      delt -= ends[r + 1];
      delt += ends[l];
      delt += starts[r + 2];
      ct[i][j] = ct[i][j - 1] + delt;

    }
    debug(i, ct[i]);
  }
  debug(ct);
  for (int i = M - 1; i > 0; --i) {
    for (int j = 0; j <= X; ++j) {
      ct[i - 1][j] += ct[i][j];
    }
  }
  debug(ct);
  
  const long long inf = (long long)1e17;
  vector<vector<long long>> dp(X + 1, vector<long long>(M + 1, -inf));
  dp[0][0] = ct[0][0];
  for (int i = 0; i < X; ++i) {
    for (int j = 0; j < M; ++j) {
      dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - ct[j][i] + ct[j][i + 1]);
    }
  }
  long long ans = -inf;
  for (int i = 0; i <= X; ++i) {
    for (int j = 0; j <= M; ++j) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
}
