---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DPL_5_A.test.cpp
    title: test/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/powmod.test.cpp
    title: test/powmod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing pl = pair<ll, ll>;\nusing vl = vector<ll>;\n\
    #define rep(i, n) for(ll i = 0; i < (ll)n; i++)\n#define rep3(i, l, r) for(ll\
    \ i = l; i < (ll)r; i++)\n#define per(i, n) for(ll i = (ll)n-1; i >= 0; i--)\n\
    #define per3(i, l, r) for(ll i = (ll)r-1; i >= (ll)l; i--)\n#define all(v) begin(v),\
    \ end(v)\n#define rall(v) rbegin(v), rend(v)\ntemplate<class T, class U> inline\
    \ void cmax(T &a, U b) { if (a < b) a = b; }\ntemplate<class T, class U> inline\
    \ void cmin(T &a, U b) { if (a > b) a = b; }\nconstexpr char el = '\\n';\ntemplate<class\
    \ T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << p.first\
    \ << \" \" << p.second; return os; }\ntemplate<class T, class U> istream &operator>>(istream\
    \ &is, pair<T, U> &p) { is >> p.first >> p.second; return is; }\ntemplate<class\
    \ T> ostream &operator<<(ostream &os, const vector<T> &v) { rep(i, v.size()) os\
    \ << v[i] << (i+1 != (ll)v.size() ? \" \" : \"\"); return os; }\ntemplate<class\
    \ T> istream &operator>>(istream &is, vector<T> &v) { for(T &i : v) is >> i; return\
    \ is; }\nstruct IoSetup {\n  IoSetup() { cin.tie(nullptr); ios::sync_with_stdio(false);\
    \ cout << fixed << setprecision(15); cerr << fixed << setprecision(15); }\n} io_setup;\n\
    #line 3 \"src/powmod.hpp\"\n\nll powmod(ll base, ll exp, ll mod) {\n  ll res =\
    \ 1;\n  while (exp) {\n    if (exp&1) res = res * base % mod;\n    base = base\
    \ * base % mod;\n    exp >>= 1;\n  }\n  return res;\n}\n"
  code: "#pragma once\n#include \"template.hpp\"\n\nll powmod(ll base, ll exp, ll\
    \ mod) {\n  ll res = 1;\n  while (exp) {\n    if (exp&1) res = res * base % mod;\n\
    \    base = base * base % mod;\n    exp >>= 1;\n  }\n  return res;\n}\n"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/powmod.hpp
  requiredBy: []
  timestamp: '2020-11-26 22:58:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/powmod.test.cpp
  - test/DPL_5_A.test.cpp
documentation_of: src/powmod.hpp
layout: document
redirect_from:
- /library/src/powmod.hpp
- /library/src/powmod.hpp.html
title: src/powmod.hpp
---
