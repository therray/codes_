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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  const int A = 2;
  int N;
  cin >> N;
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
  debug(mat);

  auto Add = [&](int x, int y) {
    x += y;
    if (x > md) {
      x -= md;
    }
    return x;
  };
  vector<vector<int>> dp(N + 1, vector<int>(A, 0));
  dp[0] = vector<int>(A, 1);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < A; ++j) {
      for (int n = 0; n < A; ++n) {
        if (i + mat[j][n] <= N) {
          dp[i + mat[j][n]][n] = Add(dp[i + mat[j][n]][n], dp[i][j]);
        }
      }
    }
  }
  
  int ans = 0;
  for (int i = 0; i < A; ++i) {     
    for (int j = 0; j <= N; ++j) {
      ans = Add(ans, dp[j][i]);
    }
  }
  cout << ans << '\n';
}