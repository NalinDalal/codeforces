/*D. Tree Jumps
time limit per test2 seconds
memory limit per test512 megabytes
You are given a rooted tree, consisting of 𝑛
 vertices. The vertices in the tree are numbered from 1
 to 𝑛
, and the root is the vertex 1
. Let 𝑑𝑥
 be the distance (the number of edges on the shortest path) from the root to the
vertex 𝑥
.

There is a chip that is initially placed at the root. You can perform the
following operation as many times as you want (possibly zero):

move the chip from the current vertex 𝑣
 to a vertex 𝑢
 such that 𝑑𝑢=𝑑𝑣+1
. If 𝑣
 is the root, you can choose any vertex 𝑢
 meeting this constraint; however, if 𝑣
 is not the root, 𝑢
 should not be a neighbor of 𝑣
 (there should be no edge connecting 𝑣
 and 𝑢
).

For example, in the tree above, the following chip moves are possible: 1→2
, 1→5
, 2→7
, 5→3
, 5→4
, 3→6
, 7→6
.

A sequence of vertices is valid if you can move the chip in such a way that it
visits all vertices from the sequence (and only them), in the order they are
given in the sequence.

Your task is to calculate the number of valid vertex sequences. Since the answer
might be large, print it modulo 998244353
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤3⋅105
).

The second line contains 𝑛−1
 integers 𝑝2,𝑝3,…,𝑝𝑛
 (1≤𝑝𝑖<𝑖
), where 𝑝𝑖
 is the parent of the 𝑖
-th vertex in the tree. Vertex 1
 is the root.

Additional constraint on the input: the sum of 𝑛
 over all test cases doesn't exceed 3⋅105
.

Output
For each test case, print a single integer — the number of valid vertex
sequences, taken modulo 998244353
.

Example
InputCopy
3
4
1 2 1
3
1 2
7
1 2 2 1 4 5
OutputCopy
4
2
8
Note
In the first example, the following sequences are valid: [1]
, [1,2]
, [1,4]
, [1,4,3]
.

In the second example, the following sequences are valid: [1]
, [1,2]
.

In the third example, the following sequences are valid: [1]
, [1,2]
, [1,2,7]
, [1,2,7,6]
, [1,5]
, [1,5,3]
, [1,5,3,6]
, [1,5,4]
.
*/

#include <bits/stdc++.h>
using namespace std;

const long long M = 998244353;

vector<vector<int>> adj;
vector<int> lev;

void dfs(int x) {
  for (int i : adj[x]) {
    lev[i] = lev[x] + 1;
    dfs(i);
  }
}

void solve() {
  int n;
  cin >> n;

  vector<int> p(n + 1);
  adj.assign(n + 1, {});
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    adj[p[i]].push_back(i);
  }

  lev.assign(n + 1, 0);
  dfs(1);

  vector<vector<int>> vec(n);
  for (int i = 1; i <= n; i++) {
    vec[lev[i]].push_back(i);
  }

  vector<long long> dp(n + 1);
  long long sum = 0;

  for (int i = n - 1; i >= 1; i--) {
    if (vec[i].empty())
      continue;

    long long s = 0;
    for (int v : vec[i]) {
      dp[v] = (1 + sum) % M;
      for (int u : adj[v]) {
        dp[v] -= dp[u];
        dp[v] = (dp[v] % M + M) % M;
      }
      s += dp[v];
      s %= M;
    }
    sum = s;
  }

  long long ans = (sum + 1) % M;
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2070/336762281
