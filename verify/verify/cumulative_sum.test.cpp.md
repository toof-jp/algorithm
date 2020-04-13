---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: verify/cumulative_sum.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8418d1d706cd73548f9f16f1d55ad6e">verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/cumulative_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-14 02:24:11+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516</a>


## Depends on

* :heavy_check_mark: <a href="../../library/cumulative_sum.hpp.html">cumulative_sum.hpp</a>
* :heavy_check_mark: <a href="../../library/template.hpp.html">template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define  PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516"

#include "../template.hpp"
#include "../cumulative_sum.hpp"

int main() {
  while (1) {
    ll n, k;
    cin >> n >> k;
    if (n == 0 and k == 0) return 0;
    vl a(n);
    rep(i, n) {
      cin >> a[i];
    }

    CumulativeSum<ll> cs(a);
    cs.build();
    ll ans = -1e4;
    for (ll i = 0; i+k-1 < n; i++) {
      cmax(ans, cs.sum(i, i+k-1));
    }

    cout << ans << el;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/cumulative_sum.test.cpp"
#define  PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516"

#line 2 "template.hpp"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
#define rep(i, n) for(ll i = 0; i < (ll)n; i++)
#define rep3(i, l, r) for(ll i = l; i < (ll)r; i++)
#define per(i, n) for(ll i = (ll)n-1; i >= 0; i--)
#define per3(i, l, r) for(ll i = (ll)r-1; i >= (ll)l; i--)
#define all(v) begin(v), end(v)
template<class T, class U>
inline void cmax(T& a, U b) { if (a < b) a = b; }
template<class T, class U>
inline void cmin(T& a, U b) { if (a > b) a = b; }

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);
  }
} io_setup;

constexpr char el = '\n';

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U>& p) {
  os << p.first << " " << p.second;
  return os;
}
template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template<typename T>
ostream &operator<<(ostream &os, const vector< T > &v) {
  rep(i, v.size())
    os << v[i] << (i + 1 != v.size() ? " " : "");
  return os;
}
template<typename T>
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}
#line 3 "cumulative_sum.hpp"

template<class T>
struct CumulativeSum {
  vector<T> v;

  CumulativeSum(size_t n) : v(n+1) {};
  CumulativeSum(vector<T> v_) {
    v.resize(v_.size()+1);
    rep(i, v_.size())
      v[i+1] = v_[i];
  };

  void add(size_t i, T x) {
    v[i+1] += x;
  }

  // O(N)
  void build() {
    if (v.size() == 0) return;
    rep(i, v.size()-1)
      v[i+1] += v[i];
  }

  // O(1) sum [l, r]
  T sum(size_t l, size_t r) const {
    return l == 0 ? v[r+1] : v[r+1]-v[l];
  }

  // O(1) sum [0, r]
  T sum(size_t r) const {
    return v[r+1];
  }

  T& operator[](size_t i) {
    return v[i];
  }

  const T& operator[](size_t i) const {
    return v[i];
  }
};
#line 5 "verify/cumulative_sum.test.cpp"

int main() {
  while (1) {
    ll n, k;
    cin >> n >> k;
    if (n == 0 and k == 0) return 0;
    vl a(n);
    rep(i, n) {
      cin >> a[i];
    }

    CumulativeSum<ll> cs(a);
    cs.build();
    ll ans = -1e4;
    for (ll i = 0; i+k-1 < n; i++) {
      cmax(ans, cs.sum(i, i+k-1));
    }

    cout << ans << el;
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
