/*C. The Nether
time limit per test3 seconds
memory limit per test256 megabytes

This is an interactive problem.

Having recently discovered The Nether, Steve has built a network of 𝑛
 nether portals, each at a different location in his world.

Each portal is connected in one direction to some number (possibly zero) of
other portals. To avoid getting lost, Steve has carefully built the network of
portals so that there is no sequence of jumps through portals that will bring
you from a location back to itself; formally, the network forms a directed
acyclic graph.

Steve refuses to tell you which portals are connected to which, but he will
allow you to ask queries. In each query, you give Steve a set of locations
𝑆={𝑠1,𝑠2,…,𝑠𝑘} and a starting location 𝑥∈𝑆 . Steve will figure out the longest
path starting at 𝑥 that only passes through locations in 𝑆 and tell you the
number of locations in it. (If it is impossible to reach any other location in 𝑆
 from 𝑥
, Steve will reply with 1
.)

As you are looking to obtain the achievement "Hot Tourist Destinations", you
want to find any path that visits as many locations as possible. Steve is
feeling particularly generous and will give you 2⋅𝑛 queries to find it.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The only line of each test case contains a single integer 𝑛
 (2≤𝑛≤500
) — the number of locations.

It is guaranteed that the sum of 𝑛3
 over all test cases does not exceed 5003
.

Interaction
The interaction for each test case begins with reading the integer 𝑛
. Then you can make up to 2⋅𝑛
 queries.

To make a query, output a line in the following format:

?𝑥𝑘𝑠1𝑠2…𝑠𝑘
The jury will return the answer to the query.

When you find a path with maximum length, output a single line in the following
format:

!𝑘𝑣1𝑣2…𝑣𝑘
This denotes starting at portal 𝑣1
, then jumping to 𝑣2
, then to 𝑣3
 and so on, ending at 𝑣𝑘
.

Note that outputting the answer does not count towards the limit of 2⋅𝑛
 queries.

After printing each query do not forget to output the end of line and flush∗
 the output. Otherwise, you will get Idleness limit exceeded verdict.

If, at any interaction step, you read −1
 instead of valid data, your solution must exit immediately. This means that
your solution will receive Wrong answer because of an invalid query or any other
mistake. Failing to exit can result in an arbitrary verdict because your
solution will continue to read from a closed stream.

The interactor is not adaptive. The connections between portals do not change
during the interaction.

Hacks

To perform a hack, use the following format:

Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤500
) — the number of locations.

Then, output 𝑛
 lines. The 𝑖
-th line should be of the form 𝑘𝑖𝑣1𝑣2…𝑣𝑘𝑖
 (0≤𝑘𝑖≤𝑛−1
, 1≤𝑣𝑗≤𝑛
, 𝑣𝑗≠𝑖
), denoting that the portal at location 𝑖
 is connected in one direction (leads to) locations 𝑣1,𝑣2,…,𝑣𝑘𝑖
. The given network must form a directed acyclic graph.

The sum of 𝑛3
 over all test cases must not exceed 5003
.

∗
To flush, use:

fflush(stdout) or cout.flush() in C++;
sys.stdout.flush() in Python;
see the documentation for other languages.
Example
InputCopy
2
5

3

3

2

1


2

1

1
OutputCopy

? 1 4 1 2 3 4

? 3 3 4 3 2

? 5 2 1 5

? 2 2 2 4

! 4 5 1 4 2


? 1 2 1 2

? 2 2 1 2

! 1 1
Note
In the first test case, the network of portals is as follows:


The longest path starting at location 1
 passing only through {1,2,3,4}
 is the path 1→4→2
, which has 3
 distinct locations.
The longest path starting at location 3
 passing only through {2,3,4}
 is the path 3→4→2
, which has 3
 distinct locations.
The longest path starting at location 5
 passing only through {1,5}
 is the path 5→1
, which has 2
 distinct locations.
It is impossible to get to any other location in {2,4}
 starting from 2
, so Steve answers 1
 for that query.
Using the information from these queries, it is possible to determine that a
longest path is 5→1→4→2
.
In the second test case, the network of portals is as follows:


Neither of the portals is connected to the other, so the longest path is a
single location. Note that ! 1 2 would also be a valid answer.
*/

#include <bits/stdc++.h>
using namespace std;

#define fastIO                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);                                                            \
  cout.tie(nullptr);

int query(int x, const vector<int> &vec) {
  cout << "? " << x << " " << vec.size();
  for (int v : vec)
    cout << " " << v;
  cout << endl;
  cout.flush();

  int ans;
  if (!(cin >> ans))
    exit(0);
  if (ans == -1)
    exit(0); // handle invalid query case
  return ans;
}

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> vec(n + 2); // vec[len] -> nodes having that path length
  vector<int> all;
  for (int i = 1; i <= n; i++)
    all.push_back(i);

  // Step 1: Query every node over all nodes
  for (int i = 1; i <= n; i++) {
    int len = query(i, all);
    if (len >= (int)vec.size())
      vec.resize(len + 1);
    vec[len].push_back(i);
  }

  // Step 2: Build path from deepest level upwards
  vector<int> ans;
  int last = -1;

  for (int len = n; len >= 1; len--) {
    if (vec[len].empty())
      continue;

    if (last == -1) {
      last = vec[len][0];
      ans.push_back(last);
      continue;
    }

    for (int node : vec[len]) {
      int res = query(last, {last, node});
      if (res == 2) {
        ans.push_back(node);
        last = node;
        break;
      }
    }
  }

  cout << "! " << ans.size();
  for (int v : ans)
    cout << " " << v;
  cout << endl;
  cout.flush();
}

int main() {
  fastIO;
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2133/342867484
