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

struct DSU {
  vector<int> par;
  DSU(int n) {
    par.resize(n);
    iota(par.begin(), par.end(), 0);
  }  
  
  inline int get(int x) {
    return par[x] = (x == par[x] ? x : get(par[x]));
  }

  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    par[y] = x;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> P(N);
  DSU d(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    d.unite(i, P[i]);
  }

  vector<vector<int>> g(N);
  for (int i = 0; i < N; ++i) {
    g[d.get(i)].push_back(i);
  }
  for (int i = 0; i < N; ++i) {
    sort(g[i].begin(), g[i].end(), [&](int x, int y) {
      return A[x] < A[y];
    });
  }
  debug(g);

  int mn = *min_element(A.begin(), A.end());
  long long ans = accumulate(A.begin(), A.end(), 0LL);
  debug(ans);
  for (auto e : g) {
    if (e.empty()) {
      continue;
    }
    ans += min(1LL * (int(e.size()) - 2) * A[e[0]], 0LL + A[e[0]] + 1LL * mn * (int(e.size()) + 1));
  }
  cout << ans << '\n';
}