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
  int TT;
  cin >> TT;
  while (TT--) {
    int H, N, M;
    cin >> H >> N >> M;
    vector<array<long long, 3>> S(N);
    for (int i = 0; i < N; ++i){
      cin >> S[i][0] >> S[i][1] >> S[i][2];
    }
    vector<array<long long, 3>> D(M);
    for (int i = 0; i < M; ++i) {
      cin >> D[i][0] >> D[i][1] >> D[i][2];
    }
    {
      sort(S.begin(), S.end());
      sort(D.begin(), D.end());
      debug(S, D);
      long long ans = H;
      for (auto[foo1, foo2, h] : D) {
        ans = min(ans, H - h);
      }
      int pl = 0, pr = 0;
      multiset<int> ms;
      ms.insert(0);
      for (auto[l, r, h] : S) {
        while (pr < M && D[pr][0] <= r) {
          ms.insert(D[pr][2]);
          ++pr;
        }      
        while (pl < M && D[pl][1] < l) {
          ms.erase(ms.find(D[pl][2]));
          ++pl;
        }
        debug(ms);
        debug(H - h - (*prev(ms.end())));
        ans = min(ans, H - h - (*prev(ms.end())));
      }
      cout << ans << ' ';
    }
    {
      const long long inf = (long long) 1e17;
      long long ans = inf;
      for (auto&[l, r, h] : D){
        h = H - h;
      }
      sort(D.begin(), D.end(), [&](array<long long, 3> x, array<long long, 3> y) {
        return x[2] < y[2];
      });
      set<pair<long long, long long>> st;
      sort(S.begin(), S.end(), [&](array<long long, 3> x, array<long long, 3> y) {
        return x[2] < y[2];
      });
      debug(S, D);
      int p = 0;
      for (auto[l, r, h] : S) {
        while (p < M && D[p][2] <= h) {
          st.emplace(D[p][0], D[p][1]);
          ++p;
        }
        auto it = st.lower_bound(pair<long long, long long>{l, r});
        if (it != st.end()) {
          assert(it->first >= r);
          ans = min(ans, it->first - r);  
        }
        if (it != st.begin()) {
          it = prev(it);
          assert(it->second <= l);
          ans = min(ans, l - it->second);
          
        }
      }
      cout << (ans == inf ? -1LL : ans) << '\n';
    }
  }
}
