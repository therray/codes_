// author: erray
#include <bits/stdc++.h>
 
using namespace std;

template<typename A, typename B> string to_string(const pair<A, B>& p);
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t);
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char& c) {
  return string("'") + c + "'";
}

string to_string(const char *c) {
  return to_string(string(c));
}

string to_string(const bool& b) {
  return (b ? "true" : "false");
}

string to_string(const vector<bool>& v) {
  string res = "{";
  for (int i = 0; i < (int) v.size(); ++i) {
    if (i > 0) {
      res += ", ";
    }
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template<size_t T> string to_string(const bitset<T>& bs) {
  return bs.to_string();
}

template<typename T> string to_string(queue<T> q) {
  string res = "{";
  size_t sz = q.size();
  while (sz--) {
    T cur = q.front();
    q.pop();
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
  }
  res += "}";
  return res;
}

template<typename T, class C> string to_string(priority_queue<T, vector<T>, C> pq) {
  string res = "{";
  while (!pq.empty()) {
    T cur = pq.top();
    pq.pop();
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
  }
  res += "}";
  return res;
}

template<typename T> string to_string(const T& v) {
  string res = "{";
  for (auto &el : v) {
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(el);
  }
  res += "}";
  return res;
}

template<typename A, typename B> string to_string(const pair<A, B>& p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ')';
}
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ')';
}

void debug_out(int size, bool first, string name) {
  vector<string> tmp = {name};
  vector<int> tmp2 = {size, first};
  cerr << endl;
}

constexpr int buffer_size = 255;

template<typename Head, typename... Tail> void debug_out(int size, bool first, string name, Head H, Tail... T) {
  string tmp;
  int off = 0;
  while ((!name.empty() && name[0] != ',') || off != 0) {
    tmp += name[0];
    name.erase(name.begin());
    char c = tmp.back();
    if (c == '{' || c == '(') {
      ++off;
    } else if (c == '}' || c == ')'){
      --off;
    }
  }
  if (!name.empty()) {
    name.erase(name.begin());
  }
  if (tmp[0] == ' ') {
    tmp.erase(tmp.begin());
  }

  string buff = to_string(H);
  if ((int) buff.size() + size + (int) tmp.size() > buffer_size - 5 && !first) {
    cerr << '\n';
    size = 0;
  }
  cerr << '[' << tmp << ": " << buff << "] ";
  debug_out(((int) buff.size() + size + (int) tmp.size() + 5) % buffer_size, false, name, T...);
}

#ifdef DEBUG
#define debug(...) cerr << "-> ", debug_out(3, true, string(#__VA_ARGS__), __VA_ARGS__)
#define here cerr << "-> " << __LINE__ << endl
#else
#define debug(...) void(37)
#define here void(37)
#endif
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<vector<int>> new_g(n);
  vector<bool> vis(n);       
  vector<int> d(n);
  vector<array<int, 2>> es;
  vector<int> par(n, -1);
  vector<int> par_id(n, -1);
  function<void(int)> Dfs = [&](int v) {
    vis[v] = true;
    for (auto u : g[v]) {
      if (!vis[u]) {
        par[u] = v;
        new_g[v].push_back(int(es.size()));
        new_g[u].push_back(int(es.size()));
        par_id[u] = int(es.size());
        es.push_back({v, u});
        d[u] = d[v] + 1;
        Dfs(u);
      }
    }
  };
  Dfs(0);
  swap(g, new_g);
  debug(g);
  int q;
  cin >> q;
  vector<array<int, 2>> qs(q);
  for (int i = 0; i < q; ++i) {
    cin >> qs[i][0] >> qs[i][1];
    --qs[i][0], --qs[i][1];
    if (d[qs[i][0]] > d[qs[i][1]]) {
      swap(qs[i][0], qs[i][1]);
    }
  }

  vector<int> ct(n - 1);
  vector<vector<int>> ans;
  for (auto[x, y] : qs) {
    auto[ox, oy] = pair{x, y};
    int lca;
    while (d[y] > d[x]) {
      y = par[y];    
    }
    debug(x, y);
    debug(ox, oy);
    while (x != y) {
      x = par[x];
      y = par[y];
    } 
    lca = x;

    tie(x, y) = pair{ox, oy};
    auto P = [&](int v) {
      debug(v);
      vector<int> res;
      while (v != lca) {
        debug(v);
        res.push_back(v);
        ++ct[par_id[v]];
        v = par[v];   
        debug(v);
      }
      return res;
    };

    debug(x, y);
    auto px = P(x);
    auto py = P(y);
    debug(px, py);
    reverse(py.begin(), py.end());
    px.push_back(lca);
    px.insert(px.end(), py.begin(), py.end());
    ans.push_back(px);
  }
  
  int c = 0;
  for (int i = 0; i < n - 1; ++i) {
    c += ct[i] % 2;
  }

  if (c == 0) {
    cout << "YES\n";
    for (auto e : ans) {
      cout << int(e.size()) << '\n';
      for (auto v : e) {
        cout << v + 1 << ' ';
      }
      cout << '\n';
    }
    return 0;
  }

  cout << "NO\n";
  for (int i = 0; i < n; ++i) {
    int cc = 0;
    for (auto id : g[i]) {
      cc += ct[id] % 2;
    }
    c -= cc / 2;
  }
  cout << c << '\n';
}