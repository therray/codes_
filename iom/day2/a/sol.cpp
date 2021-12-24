//author: erray
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
string to_string(char c) {
  return "'"s + c + "'";
}
string to_string(bool b) {
  return (b ? "true" : "false");
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
template<typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template<typename A, typename B, typename C> string to_string(tuple<A, B, C> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
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
  string S;
  cin >> S;
  if (count(S.begin(), S.end(), '*') == 0) {
    long long x = 0;
    reverse(S.begin(), S.end());
    long long b = 1;
    for (char c : S) {
      x += (c - '0') * b;
      b *= 10;
    }
    debug(x);
    bool p = true;
    for (long long i = 2; i * i <= x; ++i) {
      p &= (x % i != 0);
    }
    if (p) {
      cout << -1 << '\n';
    } else {
      cout << x << '\n';
    }
  } else {
    if (int(S.size()) == 1) {
      cout << 8 << '\n';
      return 0;
    }
    int p = int(S.size()) - 1;
    while (S[p] != '*') {
      --p;
    }
    for (int i = 0; i < p; ++i) {
      if (S[i] == '*') {
        S[i] = '0' + (i == 0);
      } 
    }
    int sum = 0;
    int l = 0;
    debug(S);
    for (char c : S) {
      if (c != '*') {
        sum += c - '0';
      } else {
        l += 1;
      }
    }
    assert(l == 1);
    for (int i = 1; i <= 3; ++i) {
      if ((sum + i) % 3 == 0) {
        S[p] = '0' + i;
        sum += i;
      }
    }
    assert(sum % 3 == 0);
    cout << S << '\n'; 
  }
}