/*C. Divine Tree
time limit per test2 seconds
memory limit per test256 megabytes

Harshith attained enlightenment in Competitive Programming by training under a
Divine Tree. A divine tree is a rooted tree∗ with 𝑛 nodes, labelled from 1 to 𝑛
. The divineness of a node 𝑣
, denoted 𝑑(𝑣)
, is defined as the smallest node label on the unique simple path from the root
to node 𝑣
.

Aryan, being a hungry Competitive Programmer, asked Harshith to pass on the
knowledge. Harshith agreed on the condition that Aryan would be given two
positive integers 𝑛 and 𝑚 , and he had to construct a divine tree with 𝑛 nodes
such that the total divineness of the tree is 𝑚 , i.e., ∑𝑖=1𝑛𝑑(𝑖)=𝑚 . If no such
tree exists, Aryan must report that it is impossible.

Desperate for knowledge, Aryan turned to you for help in completing this task.
As a good friend of his, help him solve the task.

∗
A tree is a connected graph without cycles. A rooted tree is a tree where one
vertex is special and called the root.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛≤106
, 1≤𝑚≤1012
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 106
.

Output
For each test case, output a single integer 𝑘
 in one line — the root of the tree.

Then 𝑛−1
 lines follow, each containing a description of an edge of the tree — a pair of
positive integers 𝑢𝑖,𝑣𝑖 (1≤𝑢𝑖,𝑣𝑖≤𝑛 , 𝑢𝑖≠𝑣𝑖
), denoting the 𝑖
-th edge connects vertices 𝑢𝑖
 and 𝑣𝑖
.

The edges and vertices of the edges can be printed in any order. If there are
multiple solutions, print any of them.

If there is no solution, print "-1" instead.

Example
InputCopy
2
1 2
4 6
OutputCopy
-1
3
3 1
1 2
2 4
Note
In the first test case, there is a single node with a value of 1
, so getting a sum of 2
 is impossible.

In the second test case, getting a sum of 6
 is possible with the given tree rooted at 3
.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    ll m;
    cin >> n >> m;
    if ((m < n) || (m > (ll)n * (n + 1) / 2)) {
      cout << "-1\n";
      continue;
    }

    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
      vals[i] = i + 1;
    }
    ll rem = (ll)n * (n + 1) / 2 - m;
    for (int i = n - 1; i >= 0; i--) {
      if (rem <= vals[i] - 1) {
        vals[i] -= rem;
        rem = 0;
      } else {
        rem -= (vals[i] - 1);
        vals[i] = 1;
      }
      if (rem <= 0)
        break;
    }

    int root = *max_element(vals.begin(), vals.end());

    cout << root << "\n";

    for (int i = 0; i < n; i++) {
      if (vals[i] == i + 1) {
        if (i + 1 == root)
          continue;
        cout << i + 1 << " " << root << "\n";
      } else {
        cout << i + 1 << " " << vals[i] << "\n";
      }
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2120/341158268
