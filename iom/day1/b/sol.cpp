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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, K, T;
  cin >> N >> K >> T;
  if (K < N - 1 || K > 1LL * N * (N - 1) / 2) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  if (T == 1) {
    K -= N - 1;
    vector<int> par(N, 0);  
    int p = 0;
    while (1LL * p * (p + 1) / 2 <= K) {
      ++p;
    }
    debug(p);
    K -= p * (p - 1) / 2;
    for (int i = 1; i <= p; ++i) {
      par[i] = i - 1;
    }
    for (int i = p + 1; i < N; ++i) {
      int x = min(K, p);
      par[i] = x;
      K -= x;
    }

    for (int i = 1; i < N; ++i) {
      cout << par[i] + 1 << ' ';
    }
    cout << '\n';
  }         
}