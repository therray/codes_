// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
Mint B = uniform_int_distribution<int>(int(1e6), int(1e7))(rng);
Mint inv_B = Mint(1) / B;

struct SmallHash {
  int md = -1;
  int value = 0;
  void add(char c) {
    if (c == '+') {
      if ((value += 1) == md) {
        value = 0;
      }
    } else if (c == '-') {
      if ((value -= 1) < 0) {
        value = md - 1;
      }
    } else if (c == '>') {
      value = 1LL * value * B % md;
    } else if (c == '<') {
      value = 1LL * value * inv_B % md;
    } else {
      assert(false);
    }
  }
  bool operator<(const Hash& ot) {
    return value < ot.value;
  }  
};

template<vector<int> mods> struct Hash {
  vector<SmallHash> a;
  Hashes() {
    a.resize(int(mods.size()));
    for (int i = 0; i < int(mods.size()); ++i) {
      a[i].md = mods[i]; 
    }  
  }

  bool operator<(Hashes& ot) {
    return a < ot.a;
  }

  void add(char c) {
    for (auto& e : a) {
      e.add(c);
    }
  }

  void inverse_add(char c) {
    if (c == '+') {
      c = '-';
    } else if (c == '-') {
      c = '+';
    } else if (c == '>') {
      c = '<';
    } else if (c == '<') {
      c = '>';
    }
    add(c);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  // count inverses from suffixes
  using hash = Hash<{1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181}>;
  
  hash tar;
  for (int i = n - 1; i >= 0; --i) {
    tar.add(s[i]);
  }

  map<

   
}