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

constexpr int md = int(1e9) + 7;
int Add(int x, int y) {
  if ((x += y) > md) {
    x -= md;
  }
  return x;
}

int mul(int x, int y) {
  return (1LL * x * y) % md;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  constexpr int A = 2;
  array<array<int, A>, A> mat;
  for (int i = 0; i < A; ++i) {
    mat[i].fill(1);
  }

  int M;
  cin >> M;
  for (int i = 0; i < M; ++i) {
    char X, Y;
    int C;
    cin >> X >> Y >> C;
    X -= 'a';
    Y -= 'a';
    mat[X][Y] = mat[Y][X] = C;
  }

  using matrix = array<array<int, A>, A>;
  map<int, matrix> all;
  map<int, matrix> lower;
  matrix push = {};
  for (int i = 0; i < A; ++i) {
    push[i][i] = 1;
  }
  all[0] = lower[0] = push;

  function<void(int)> DP = [&](int x) {
    if (all.count(x)) {
      return;
    }  

    int from = (x + 1) >> 1;
    if (x > 10) {
      DP(from);
    }
    auto& lower_me = lower[x];
    auto& all_me = all[x];
    auto& lower_from = lower[from];
    auto& all_from = all[from];
    for (int i = 0; i < A; ++i) {
      for (int j = 0; j < A; ++j) {
        lower_me[i][j] = lower_from[i][j];
        all_me[i][j] = 0;
      }
    }

    for (int i = 1; i <= min(x, 5); ++i) {
      int ot = x - from - i;      
      if (x <= 10) {
        from = i;
        ot = x - i;
        DP(from);
      }
      DP(ot);
      auto& lower_ot = lower[ot];
      auto& all_ot = all[ot];
      for (int r1 = 0; r1 < A; ++r1) {
        for (int l2 = 0; l2 < A; ++l2) {
          if (mat[r1][l2] != i) {
            continue;
          } 
          for (int l1 = 0; l1 < A; ++l1) {
            for (int r2 = 0; r2 < A; ++r2) {
              int l = l1;
              int r = r2;
              all_me[l][r] = Add(all_me[l][r], mul(all_from[l1][r1], all_ot[l2][r2]));
              lower_me[l][r] = Add(lower_me[l][r], mul(all_from[l1][r1], lower_ot[l2][r2]));
            }
          }
        }
      }
    }        
  };
                    
  /*
  auto cit = all.begin();
  while (!lower.count(N)) {
    auto[c1, m1] = *prev(all.end());
    while (cit != all.end() && c1 + cit->first <= N - 5) {
      ++cit;
    }
    if (cit != all.begin()) {
      cit = prev(cit);
    }
    auto[c2, m2] = (*cit);
    matrix lower1 = lower[c1];
    matrix lower2 = lower[c2];
    debug(c1, c2);
    vector<matrix> all_p(6, matrix{});
    vector<matrix> lower_p(6, matrix{});
    vector<bool> added(6);
    for (int l1 = 0; l1 < A; ++l1) {
      for (int r1 = 0; r1 < A; ++r1) {
        for (int j = 1; j <= 5; ++j) {
          lower_p[j][l1][r1] = Add(lower_p[j][l1][r1], lower1[l1][r1]);
        }
        for (int l2 = 0; l2 < A; ++l2) {
          for (int r2 = 0; r2 < A; ++r2) {
            int add = mat[r1][l2];
            if (c1 + c2 + add > N) {
              continue;
            }  
            int l = l1;
            int r = r2;
            all_p[add][l][r] = Add(all_p[add][l][r], mul(m1[l1][r1], m2[l2][r2]));
            lower_p[add][l][r] = Add(lower_p[add][l][r], mul(m1[l1][r1], lower2[l2][r2]));
            added[add] = true;           
          }
        }  
      }
    }
    for (int i = 1; i <= 5; ++i) {
      if (added[i]) {
        assert(c1 + c2 + i <= N);
        all[c1 + c2 + i] = all_p[i];
        lower[c1 + c2 + i] = lower_p[i];
      }
    }
  }
  */
  DP(N);
  debug(lower);
  debug(all);
  int ans = 0;
  for (int i = 0; i < A; ++i) {
    for (int j = 0; j < A; ++j) {
      ans = Add(ans, lower[N][i][j]);
    }
  }
  cout << ans << '\n'; 
}