/* A. Recent Actions
time limit per test1 second
memory limit per test256 megabytes
On Codeforces the "Recent Actions" field shows the last 𝑛
 posts with recent actions.

Initially, there are posts 1,2,…,𝑛
 in the field (this is in order from top to down). Also there are infinitely
many posts not in the field, numbered with integers 𝑛+1,𝑛+2,…
.

When recent action happens in the post 𝑝
:

If it is in the "Recent Actions" field, it moves from its position to the top
position. Otherwise, it is added to the top position, and the post on the down
position is removed from the "Recent Actions" field. You know, that the next 𝑚
 recent actions will happen in the posts 𝑝1,𝑝2,…,𝑝𝑚
 (𝑛+1≤𝑝𝑖≤𝑛+𝑚
) in the moments of time 1,2,…,𝑚
. Note, that recent actions only happen with posts with numbers ≥𝑛+1
.

For each post 𝑖
 (1≤𝑖≤𝑛
), find the first time it will be removed from the "Recent Actions" field or
say, that it won't be removed.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Descriptions of test cases follow.

The first line of each test case contains two integers 𝑛
, 𝑚
 (1≤𝑛,𝑚≤5⋅104
) — the size of the "Recent Actions" field and the number of actions.

The next line contains 𝑚
 integers 𝑝1,𝑝2,…,𝑝𝑚
 (𝑛+1≤𝑝𝑖≤𝑛+𝑚
).

It is guaranteed, that the sum of 𝑛
 and the sum of 𝑚
 for all test cases does not exceed 5⋅104
.

Output
For each test case print 𝑛
 integers 𝑡1,𝑡2,…,𝑡𝑛
, where 𝑡𝑖=−1
 if the post 𝑖
 won't be removed or 𝑡𝑖
 equals to the first moment of time the post 𝑖
 will be removed (1≤𝑡𝑖≤𝑚
).

Example
InputCopy
10
1 1
2
3 2
5 4
4 5
5 9 9 5 7
5 5
6 7 8 9 10
3 4
4 4 4 4
4 4
5 5 6 6
3 5
4 5 5 5 4
4 20
5 5 24 24 24 5 6 7 8 9 10 12 13 14 15 16 17 18 19 20
5 7
7 8 7 11 7 12 10
6 7
8 11 7 8 8 8 12
OutputCopy
1
-1 2 1
-1 5 2 1
5 4 3 2 1
-1 -1 1
-1 -1 3 1
-1 2 1
8 7 3 1
7 6 4 2 1
-1 -1 7 3 2 1
Note
In the first test case, the only post 1
 will be removed at the moment 1
 and replaced by the post 2
.

In the second test case the "Recent Actions" field will be (given an order from
top to down):

Before moment 1
: [1,2,3]
, after moment 1
: [5,1,2]
. Post number 3
 was removed.
Before moment 2
: [5,1,2]
, after moment 2
: [4,5,1]
. Post number 2
 was removed.
Post number 1
 won't be removed.

In the third test case the "Recent Actions" field will be (given an order from
top to down):

Before moment 1
: [1,2,3,4]
, after moment 1
: [5,1,2,3]
. Post number 4
 was removed.
Before moment 2
: [5,1,2,3]
, after moment 2
: [9,5,1,2]
. Post number 3
 was removed.
Before moment 3
: [9,5,1,2]
, after moment 3
: [9,5,1,2]
. Nothing was changed.
Before moment 4
: [9,5,1,2]
, after moment 4
: [5,9,1,2]
. The order was changed.
Before moment 5
: [5,9,1,2]
, after moment 5
: [7,5,9,1]
. Post number 2
 was removed.
Post number 1
 won't be removed.


*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n, -1);
    set<int> s;
    int idx = n - 1;
    for (int p = 1; p <= m; p++) {
      int x;
      cin >> x;
      if (!s.count(x) && idx >= 0) {
        v[idx--] = p;
      }
      s.insert(x);
    }

    for (int i = 0; i < v.size(); i++)
      cout << v[i] << " ";
    cout << endl;
  }
}
