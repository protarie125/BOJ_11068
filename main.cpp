#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll t, n;

bool check(ll n, ll b) {
  if (0 == n) {
    return true;
  }

  auto vec = vl{};
  while (0 < n) {
    vec.push_back(n % b);
    n /= b;
  }

  for (auto i = 0ULL; i < (vec.size() + 1) / 2; ++i) {
    if (vec[i] != vec[vec.size() - 1 - i]) {
      return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> t;
  while (0 < (t--)) {
    cin >> n;

    auto is_checked = false;
    for (auto b = 2LL; !is_checked && b <= 64LL; ++b) {
      if (check(n, b)) {
        cout << 1 << '\n';
        is_checked = true;
        break;
      }
    }

    if (!is_checked) {
      cout << 0 << '\n';
    }
  }

  return 0;
}