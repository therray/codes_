// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  //system("gen >int");
  system("sol <int >out");
  system("bf <int >bf");
  ifstream sol("out"); 
  ifstream bf("bf");
  while (bf.eof()) {
    int X, Y;
    bf >> X;
    sol >> Y;
    assert(X == Y);  
  }
  sol.close();
  bf.close();

}