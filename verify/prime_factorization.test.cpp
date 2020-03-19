#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include "../template.cpp"
#include "../prime_factorization.cpp"

int main() {
  ll n;
  cin >> n;

  auto m = prime_factorization(n);

  cout << n << ": ";
  for (auto&& i : m) {
    rep(j, i.second) {
      cout << i.first << " ";
    }
  }
  cout << endl;
}
