//author: erray
#undef _GLIBCXX_DEBUG
#undef DEBUG
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
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<long long> dec(N + 1);
  dec[0] = 0;
  for (int i = 0; i < N; ++i) {
    dec[i + 1] = dec[i] + 1LL * i * (i + 1);
  }
  vector<array<int, 3>> QS(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> QS[i][0] >> QS[i][1];
    QS[i][2] = i;
    --QS[i][0], --QS[i][1];
  }
  int SQ = int(sqrt(N)) + 1;
  sort(QS.begin(), QS.end(), [&](auto x, auto y) {
    return pair{x[0] / SQ, x[1]} < pair{y[0] / SQ, y[1]};
  });
  int MAX = *max_element(A.begin(), A.end());
  vector<long long> ans(Q);
  vector<long long> ind_dec(MAX + 1);
  vector<long  long> ct(MAX + 1);
  vector<long  long>  sum(MAX + 1);
  long long cans = 0;
  int cl = N, cr = N - 1;
  long long pr = 0;

  for (auto[l, r, id] : QS) {
    debug(/*--------------------------------------------------------------------------*/);
    debug(cl, cr);
    while (cl > l) {
      --cl;
      int x = A[cl];
      ct[x] += 1;
      sum[x] += cl;
      cans -= sum[x];
      ind_dec[x] += sum[x];
      pr += ct[x];
    }
    while (cl < l) {
      int x = A[cl];
      ind_dec[x] -= sum[x];
      cans += sum[x];
      sum[x] -= cl;
      pr -= ct[x];
      ct[x] -= 1;
      ++cl;
    }
    while (cr < r) {
      ++cr;
      int x = A[cr]; 
      ct[x] += 1;
      cans -= ct[x] * cr;
      ind_dec[x] += ct[x] * cr;
      pr += ct[x];
      sum[x] += cr;
    }
    while (cr > r) {
      int x = A[cr];
      cans += ct[x] * cr;
      ind_dec[x] -= ct[x] * cr;
      pr -= ct[x];
      ct[x] -= 1;
      sum[x] -= cr;
      --cr;
    }
    debug(l, r, id);
    debug(ct);
    debug(ind_dec);
    debug(cans);
    debug(pr, r);
    int s = r - l + 1;
    debug(s);
    long long q = 1LL * s * (s + 1) / 2;
    long long tot = q * s - dec[s];
    ans[id] = tot - (cans + (pr * (r + 1)));
  }

  debug(dec);
  for (int i = 0; i < Q; ++i) {
    cout << ans[i] << '\n';
  }         
  cerr << clock() << '\n';
}
