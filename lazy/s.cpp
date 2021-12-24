// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<string> names;
  vector<string> mottos;
  ofstream name("name.txt");
  ofstream motto("mottos.txt");
  ifstream source("input.txt");
  while (!source.eof()) {
    string S;
    getline(source, S);
    while (S[0] < 'A' || S[0] > 'z') {
      S.erase(S.begin());
    }

    /*
    for (int i = 0; i < int(S.size()); ++i) {
      cout << int(S[i]) << ' ';
    }
    */

    //debug(S);
    int N = int(S.size());
    vector<string> words;
    int p = -1;
    for (int i = 0; i < N; ++i) {
      if ((i == N - 1 || S[i + 1] == ' ' || int(S[i + 1]) == 9) && S[i] != ' ') {
        int P = i;
        while (P > 0 && S[P - 1] != ' ' && S[P - 1] != 9) {
          --P;
        }
        words.push_back(S.substr(P, i - P + 1));
      }
      if (p == -1 && int(S[i]) == 9) {
        p = int(words.size());
      }
   }

    assert(p != -1);

    debug(words);
   
    string my_name;
    string my_motto;    
    for (int i = 0; i < int(words.size()); ++i) {
      string &me = (i < p ? my_name : my_motto);
      if (!me.empty()) {
        me += " ";
      }
      me += words[i];
    }
    names.push_back(my_name);
    mottos.push_back(my_motto);
  }

  for (auto e : names) {
    name << e << endl;
  }

  for (auto e : mottos) {
    motto << e << endl;
  }

}