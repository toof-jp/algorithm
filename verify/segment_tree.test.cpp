#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../template.cpp"
#include "../segment_tree.cpp"
#include "../modint.cpp"

using modint = ModInt<998244353>;

struct Func{
  modint a, b;
  Func(ll a = 1, ll b = 0) : a(a), b(b) {};
  Func(modint a, modint b) : a(a), b(b) {};
};

struct F{
  using value_type = Func;

  Func operator()(const Func& l, const Func& r) const {
    return Func(r.a*l.a, r.a*l.b+r.b);
  }
  const Func ide = Func();
};

int main() {
  ll n, q;
  cin >> n >> q;
  SegmentTree<F> seg(n);

  vector<Func> vec(n);
  rep(i, n) {
    cin >> vec[i].a >> vec[i].b;
  }

  seg.build(vec);

  rep(i, q) {
    ll t;
    cin >> t;
    if (t == 0) {
      ll x, y, z;
      cin >> x >> y >> z;
      seg.change(x, Func(y, z));
    } else {
      ll x, y, z;
      cin >> x >> y >> z;
      Func e = seg.query(x, y);
      cout << e.a*modint(z)+e.b << endl;
    }
  }
}
