/*D. Colored Portals
time limit per test2 seconds
memory limit per test256 megabytes
There are 𝑛
 cities located on a straight line. The cities are numbered from 1
 to 𝑛
.

Portals are used to move between cities. There are 4
 colors of portals: blue, green, red, and yellow. Each city has portals of two
different colors. You can move from city 𝑖 to city 𝑗 if they have portals of the
same color (for example, you can move between a "blue-red" city and a
"blue-green" city). This movement costs |𝑖−𝑗| coins.

Your task is to answer 𝑞
 independent queries: calculate the minimum cost to move from city 𝑥
 to city 𝑦
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑞
 (1≤𝑛,𝑞≤2⋅105
) — the number of cities and the number of queries, respectively.

The second line contains 𝑛
 strings of the following types: BG, BR, BY, GR, GY, or RY; the 𝑖
-th of them describes the portals located in the 𝑖
-th city; the symbol B indicates that there is a blue portal in the city, G —
green, R — red, and Y — yellow.

The 𝑗
-th of the next 𝑞
 lines contains two integers 𝑥𝑗
 and 𝑦𝑗
 (1≤𝑥𝑗,𝑦𝑗≤𝑛
) — the description of the 𝑗
-th query.

Additional constraints on the input:

the sum of 𝑛
 over all test cases does not exceed 2⋅105
;
the sum of 𝑞
 over all test cases does not exceed 2⋅105
.
Output
For each query, print a single integer — the minimum cost to move from city 𝑥
 to city 𝑦
 (or −1
 if it is impossible).

Example
InputCopy
2
4 5
BR BR GY GR
1 2
3 1
4 4
1 4
4 2
2 1
BG RY
1 2
OutputCopy
1
4
0
3
2
-1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"

void file() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

// Check if two cities share at least one portal color
bool isSame(string s[], ll a, ll b) {
  return (s[a - 1][0] == s[b - 1][0] || s[a - 1][0] == s[b - 1][1] ||
          s[a - 1][1] == s[b - 1][0] || s[a - 1][1] == s[b - 1][1]);
}

// Generate all possible city portal pairs that share a color with city a
vector<pair<char, char>> populateToCheck(ll a, string s[]) {
  a--;
  vector<string> allPossibles = {"BG", "BR", "BY", "GR", "GY", "RY"};
  vector<pair<char, char>> result;
  for (auto &ss : allPossibles) {
    if (ss != s[a] && (ss[0] == s[a][0] || ss[0] == s[a][1] ||
                       ss[1] == s[a][0] || ss[1] == s[a][1])) {
      result.push_back({ss[0], ss[1]});
    }
  }
  return result;
}

void solve() {
  ll n, q;
  cin >> n >> q;

  string s[n];
  for (ll i = 0; i < n; i++)
    cin >> s[i];

  // Map each portal-pair to set of city indices
  map<pair<char, char>, set<ll>> hm;
  for (ll i = 0; i < n; i++) {
    hm[{s[i][0], s[i][1]}].insert(i + 1);
  }

  while (q--) {
    ll a, b;
    cin >> a >> b;
    if (a > b)
      swap(a, b);

    if (isSame(s, a, b)) {
      cout << b - a << nl;
      continue;
    }

    vector<pair<char, char>> toCheck = populateToCheck(a, s);
    ll ans = LLONG_MAX;

    for (auto &c : toCheck) {
      auto it = hm[c].upper_bound(a);

      if (it != hm[c].end()) {
        ll pos = *it;
        if (pos < b)
          ans = b - a;
        else
          ans = min(ans, (pos - a) + (pos - b));
      }

      if (it != hm[c].begin()) {
        --it;
        ll pos = *it;
        ans = min(ans, (a - pos) + (b - pos));
      }
    }

    if (ans == LLONG_MAX)
      ans = -1;
    cout << ans << nl;
  }
}

int main() {
  file();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2004/336078662
