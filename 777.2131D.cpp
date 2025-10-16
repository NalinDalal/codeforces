/*D. Arboris Contractio
time limit per test2 seconds
memory limit per test256 megabytes

Kagari is preparing to archive a tree, and she knows the cost of doing so will
depend on its diameter∗ . To keep the expense down, her goal is to shrink the
diameter as much as possible first. She can perform the following operation on
the tree:

Choose two vertices 𝑠
 and 𝑡
. Let the sequence of vertices on the simple path†
 from 𝑠
 to 𝑡
 be 𝑣0,𝑣1,…,𝑣𝑘
, where 𝑣0=𝑠
 and 𝑣𝑘=𝑡
.
Remove all edges along the path. In other words, remove edges
(𝑣0,𝑣1),(𝑣1,𝑣2),…,(𝑣𝑘−1,𝑣𝑘)
.
Connect vertices 𝑣1,𝑣2,…,𝑣𝑘
 directly to 𝑣0
. In other words, add edges (𝑣0,𝑣1),(𝑣0,𝑣2),…,(𝑣0,𝑣𝑘)
.
It can be shown that the graph is still a tree after the operation.

Help her determine the minimum number of operations required to achieve the
minimal diameter.

∗
The diameter of a tree is the longest possible distance between any pair of
vertices. The distance itself is measured by the number of edges on the unique
simple path connecting them.

†
A simple path is a path between two vertices in a tree that does not visit any
vertex more than once. It can be shown that the simple path between any two
vertices is always unique.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains one integer 𝑛
 (2≤𝑛≤2⋅105
) — the number of the vertices in the tree.

The following 𝑛−1
 lines of each test case describe the tree. Each of the lines contains two
integers 𝑢 and 𝑣 (1≤𝑢,𝑣≤𝑛 , 𝑢≠𝑣 ) that indicate an edge between vertex 𝑢 and 𝑣
. It is guaranteed that these edges form a tree.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the minimum number of operations to
minimize the diameter.

Example
InputCopy
4
4
1 2
1 3
2 4
2
2 1
4
1 2
2 3
2 4
11
1 2
1 3
2 4
3 5
3 8
5 6
5 7
7 9
7 10
5 11
OutputCopy
1
0
0
4
Note
In the first test case, the diameter of the original tree is 3
. Kagari can perform an operation on 𝑠=3
 and 𝑡=4
. As the figure depicts, the operations includes the following steps:

Remove edges (3,1)
, (1,2)
 and (2,4)
.
Add edges (3,1)
, (3,2)
 and (3,4)
.

After the operation, the diameter reduces to 2
. It can be shown that 2
 is the minimum diameter.

In the second test case, the diameter of the tree is 1
. It can be shown that 1
 is already the minimum, so Kagari can perform no operation.
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int totalLeaves = 0;
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() == 1)
      ++totalLeaves;
  }

  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int count = totalLeaves - (adj[i].size() == 1);
    for (int neighbor : adj[i]) {
      if (adj[neighbor].size() == 1)
        --count;
    }
    ans = min(ans, count);
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2131/343974996
