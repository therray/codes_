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


template<typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template<typename A, typename B, typename C> string to_string(tuple<A, B, C>);

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
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  long long tot = 1;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    tot *= A[i];
  }
  {
    vector<long long> new_A;
    for (auto e : A) {
      if (e != 1) {
        new_A.push_back(e);
      }
    }
    swap(new_A, A);
    N = int(A.size());
  }
  assert(N <= 80);
  vector<long long> divs;
  {
    vector<long long> small_divs;
    vector<long long>  big_divs;
    for (int i = 1; 1LL * i * i <= K; ++i) {
      if (K % i == 0) {
        big_divs.push_back(K / i);
        small_divs.push_back(i);
      }  
    }
    if (small_divs.back() == big_divs.back()) {
      small_divs.pop_back();
    }
    divs = small_divs;
    divs.insert(divs.end(), big_divs.rbegin(), big_divs.rend());
    debug(clock());  
  }
  int size = int(divs.size());

  sort(A.begin(), A.end());
  vector<int> till(N);  
  
  {int p = 0;
  for (int i = 0; i < N; ++i) {
    while (p < size && divs[p] <= A[i]) {
      ++p;
    }
    till[i] = p;
  }}
  debug(divs, till);
  if (N == 3) {
    using T = map<long long, long long>;
    T mx;
    mx[1] = 1;
    for (int i = 0; i < 2; ++i) {
      T new_mx;
      for (auto[c, e] : mx) {
        debug(c, e);
        for (int j = 0; j < till[i] && c * divs[j] <= K; ++j) {
          if (binary_search(divs.begin(), divs.end(), c * divs[j])) {
            new_mx[c * divs[j]] = max(new_mx[c * divs[j]], e * (A[i] / divs[j]));        
          }
        }
      }
      swap(mx, new_mx);
    }
    long long ans = 0;
    for (auto[c, e] : mx) {
      if (K / c <= A[2]) {
        ans = max(ans, e * (A[2] / (K / c)));
      }
    }
    cout << ans << '\n';
    return 0;
  }

  using T = map<long long, long long>;
  T mx;
  mx[1] = 1;
  for (int i = N - 1; i >= 0; --i) {
    T new_mx;
    for (auto[c, e] : mx) {
      debug(c, e);
      for (int j = 0; j < till[i] && c * divs[j] <= K; ++j) {
        if (binary_search(divs.begin(), divs.end(), c * divs[j])) {
          new_mx[c * divs[j]] = max(new_mx[c * divs[j]], e * (A[i] / divs[j]));        
        }
      }
    }
    swap(mx, new_mx);
  }
  cout << mx[K] << '\n';
  debug(clock());
}