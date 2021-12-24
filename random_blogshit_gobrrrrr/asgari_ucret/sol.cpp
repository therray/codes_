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
  long double start, now;
  cout << "Asgari ucretin su anki dolar degerini giriniz" << endl;
  cin >> now;
  cout << "Asgari ucretin 1 gun onceki degerini giriniz" << endl;
  cin >> start;
  long double delta = now / start;
  cout << "Asgari ucretin kac gun sonraki degerini ogrenmek istiyorsunuz?" << endl;
  int x;
  cin >> x;
  int s = x;
  while (x--) {
    now *= delta;
  }
  cout << "Asgari ucretin " << s << " gun sonraki degeri:\n" << fixed << ' ' << setprecision(5) << now << endl;
}