// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

struct Treap {
  array<Treap*, 2> c = {NULL, NULL};
  int prio = uniform_int_distribution(INT_MIN, INT_MAX)(rng);
  int ind = -1;
  int size = 0;
  Treap* par = NULL;
  Treap() { }
  Treap(int _ind) : ind(_ind), size(1) { }
};

Treap* emp = new Treap();
Treap* get(Treap* x) {
  return (x == NULL ? emp : x);
}

void pull(Treap* x) {
  x->size = get(x->c[0])->size + get(x->c[1])->size + 1;
  get(x->c[0])->par = get(x->c[1])->par = x;
}

Treap* unite(Treap* l, Treap* r) {
  if (l == NULL || r == NULL || (l == r)) {
    return (l == NULL ? r : l);
  }

  if (l->prio > r->prio) {
    l->c[1] = unite(l->c[1], r);
    pull(l);
    return l;
  } else {
    r->c[0] = unite(l, r->c[0]);
    pull(r);
    return r;
  }
}

array<Treap*, 2> split(Treap* x, int c) {
  if (x == NULL) {
    return array<Treap*, 2>{x, x};
  }
  array<Treap*, 2> res;          
  int size = get(x->c[0])->size;
  if (size == c) {
    auto L = x->c[0];
    x->c[0] = get(L)->par = NULL;
    res = {L, x};
  } else if (size > c) {
    get(x->c[0])->par = NULL;
    res = split(x->c[0], c);
    x->c[0] = res[1];
    res[1] = x;
  } else {
    get(x->c[1])->par = NULL;
    res = split(x->c[1], c - size - 1);
    x->c[1] = res[0];
    res[0] = x;
  }
  pull(x);
  return res;   
}

Treap* root(Treap* x) {
  while (x->par != NULL) {
    x = x->par;
  }
  return x;
}

int get_ind(Treap* x) {
  int res = get(x->c[0])->size;
  while (x->par != NULL) {
    Treap* par = x->par;
    if (par->c[1] == x) {
      res += get(par->c[0])->size + 1;
    }
    x = par;
  }
  return res;
}

Treap* get_ith(Treap* x, int p) { 
  while (get(x->c[0])->size != p) {
    if (get(x->c[0])->size < p) {
      p -= get(x->c[0])->size + 1;
      x = x->c[1];
    } else {
      x = x->c[0];
    }
  }
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    --P[i];
  }
  
  vector<Treap*> t(N);
  
  for (int i = 0; i < N; ++i) {
    t[i] = new Treap(i);
  }

  vector<bool> vis(N);
  for (int i = 0; i < N; ++i) {
    if (vis[i]) {
      continue;
    }
    int v = i;
    do {
      vis[v] = true;
      unite(root(t[v]), t[P[v]]);
      v = P[v];
    } while (P[v] != i);
    vis[v] = true;
  }


  for (int it = 0; it < Q; ++it) {
    int T, X, Y;
    cin >> T >> X >> Y;
    if (T == 1) {
      --X, --Y;
      auto rx = root(t[X]);
      auto ry = root(t[Y]);
      if (rx != ry) {
        for (auto e : {X, Y}) {
          auto[l, r] = split((e == X ? rx : ry), get_ind(t[e]) + 1);
          unite(r, l);
        }
        unite(rx, ry);
      } else {
        auto[l, r] = split(rx, get_ind(t[X]) + 1);
        unite(r, l);
        auto[x, y] = split(root(t[Y]), get_ind(t[Y]) + 1);
        assert(x != y);
      }
      swap(P[X], P[Y]);
    } else {
      --X;
      Treap* r = root(t[X]);
      int i = (get_ind(t[X]) + Y) % r->size;
      cout << get_ith(r, i)->ind + 1 << '\n'; 
    }
  }
}