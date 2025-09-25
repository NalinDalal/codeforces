/*E. Graph Composition
time limit per test2 seconds
memory limit per test256 megabytes
You are given two simple undirected graphs 𝐹
 and 𝐺
 with 𝑛
 vertices. 𝐹
 has 𝑚1
 edges while 𝐺
 has 𝑚2
 edges. You may perform one of the following two types of operations any number
of times:

Select two integers 𝑢
 and 𝑣
 (1≤𝑢,𝑣≤𝑛
) such that there is an edge between 𝑢
 and 𝑣
 in 𝐹
. Then, remove that edge from 𝐹
.
Select two integers 𝑢
 and 𝑣
 (1≤𝑢,𝑣≤𝑛
) such that there is no edge between 𝑢
 and 𝑣
 in 𝐹
. Then, add an edge between 𝑢
 and 𝑣
 in 𝐹
.
Determine the minimum number of operations required such that for all integers 𝑢
 and 𝑣
 (1≤𝑢,𝑣≤𝑛
), there is a path from 𝑢
 to 𝑣
 in 𝐹
 if and only if there is a path from 𝑢
 to 𝑣
 in 𝐺
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of independent test cases.

The first line of each test case contains three integers 𝑛
, 𝑚1
, and 𝑚2
 (1≤𝑛≤2⋅105
, 0≤𝑚1,𝑚2≤2⋅105
) — the number of vertices, the number of edges in 𝐹
, and the number of edges in 𝐺
.

The following 𝑚1
 lines each contain two integers 𝑢
 and 𝑣
 (1≤𝑢,𝑣≤𝑛
) — there is an edge between 𝑢
 and 𝑣
 in 𝐹
. It is guaranteed that there are no repeated edges or self loops.

The following 𝑚2
 lines each contain two integers 𝑢
 and 𝑣
 (1≤𝑢,𝑣≤𝑛
) — there is an edge between 𝑢
 and 𝑣
 in 𝐺
. It is guaranteed that there are no repeated edges or self loops.

It is guaranteed that the sum of 𝑛
, the sum of 𝑚1
, and the sum of 𝑚2
 over all test cases do not exceed 2⋅105
.

Output
For each test case, output a single integer denoting the minimum operations
required on a new line.

Example
InputCopy
5
3 2 1
1 2
2 3
1 3
2 1 1
1 2
1 2
3 2 0
3 2
1 2
1 0 0
3 3 1
1 2
1 3
2 3
1 2
OutputCopy
3
0
2
0
2
Note
In the first test case you can perform the following three operations:

Add an edge between vertex 1
 and vertex 3
.
Remove the edge between vertex 1
 and vertex 2
.
Remove the edge between vertex 2
 and vertex 3
.
It can be shown that fewer operations cannot be achieved.
In the second test case, 𝐹
 and 𝐺
 already fulfill the condition in the beginning.

In the fifth test case, the edges from 1
 to 3
 and from 2
 to 3
 must both be removed.

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const char nl = '\n';

class UnionFind {
  vector<int> par;
  vector<int> sz;

public:
  UnionFind(int n) : par(n), sz(n, 1) { iota(par.begin(), par.end(), 0); }

  int find(int u) {
    if (par[u] != u)
      par[u] = find(par[u]);
    return par[u];
  }

  bool connected(int u, int v) { return find(u) == find(v); }

  bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (sz[u] < sz[v])
      swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    return true;
  }
};

void solve() {
  ll n;
  if (!(cin >> n))
    return;

  UnionFind uf1(n), uf2(n);

  ll m1, m2;
  cin >> m1 >> m2;

  vector<pair<int, int>> e1;
  e1.reserve(m1);
  vector<pair<int, int>> e2;
  e2.reserve(m2);

  for (ll i = 0; i < m1; ++i) {
    int a, b;
    cin >> a >> b;
    e1.emplace_back(a - 1, b - 1);
  }
  for (ll i = 0; i < m2; ++i) {
    int a, b;
    cin >> a >> b;
    e2.emplace_back(a - 1, b - 1);
  }

  // Build uf2 from edges of second graph
  for (auto &e : e2)
    uf2.join(e.first, e.second);

  ll ans = 0;

  // For each edge in e1: if its endpoints are connected in uf2, join them in
  // uf1, otherwise it counts toward `ans`.
  for (auto &e : e1) {
    int a = e.first, b = e.second;
    if (uf2.connected(a, b)) {
      uf1.join(a, b);
    } else {
      ++ans;
    }
  }

  // count distinct components
  unordered_set<int> s1, s2;
  s1.reserve(n);
  s2.reserve(n);
  for (int i = 0; i < n; ++i) {
    s1.insert(uf1.find(i));
    s2.insert(uf2.find(i));
  }

  cout << (ans + (ll)s1.size() - (ll)s2.size()) << nl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2060/340287890
