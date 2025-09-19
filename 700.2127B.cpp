/*B. Hamiiid, Haaamid... Hamid?
time limit per test1 second
memory limit per test256 megabytes

Mani has locked Hamid in a 1×𝑛
 grid. Initially, some cells of the grid contain walls and the rest are empty,
and Hamid is in an empty cell.

In each day, the following events happen in order:

Mani selects an empty cell and builds a wall in that cell. Note that he can not
build a wall in the cell which Hamid currently is at; Hamid selects a direction
(left or right), then If there are no walls in that direction, he will escape
the grid; Otherwise, he will move to the nearest wall in that direction and
destroy that wall. Hamid is at the position of the destroyed wall after this
day. Here is an example of a possible sequence of actions when 𝑛=6
:


Hamid is always aware of where the walls are. He wants to minimize the number of
days that he needs to escape the grid, while Mani wants to maximize it.

You have to determine the number of days Hamid needs to escape the grid if they
both act optimally.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑥
 (2≤𝑛≤2⋅105
, 1≤𝑥≤𝑛
) — the size of the grid and the initial position of Hamid. He is at the 𝑥
-th cell from left to right initially.

The second line contains a string 𝑠
 of length 𝑛
 (𝑠𝑖="#"
 or "."
) — the initial state of the grid. The 𝑖
-th cell of the grid contains a wall if 𝑠𝑖="#"
, and it is empty if 𝑠𝑖="."
.

It is guaranteed that the 𝑥
-th cell is empty, and there are at least two empty cells in the grid.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the number of days Hamid needs to
escape the grid if they both act optimally.

Example
InputCopy
4
3 1
..#
4 2
....
5 3
##..#
6 4
#...#.
OutputCopy
1
1
3
3
Note
In the first test case, Mani must build a wall in cell 2
, so Hamid can escape from the left side of the grid on the first day.

In the second test case, if Mani places the wall to the left of Hamid, Hamid can
escape from the right. And if the wall is to Hamid's right, he can escape from
the left. Thus, the answer is 1
.

In the third test case:


It can be shown that both players acted optimally in the above illustration.

In the fourth test case, we have shown an example of actions in the statements.
Note that the players did not act optimally in this example.
 */

/*(t--){
    n,x,s;
    --x //make it 0 indexed
    if already the state is #, then wl=p
    wr=p

    ta=min(n-wr+1,x+1)
    tb=min(n-x,wl+2)

    ans=max(ta,tb)
 }
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    --x; // make 0-indexed

    long wl = -1;
    for (long p = x; p >= 0; p--) {
      if (s[p] == '#') {
        wl = p;
        break;
      }
    }

    long wr = n;
    for (long p = x; p < n; p++) {
      if (s[p] == '#') {
        wr = p;
        break;
      }
    }

    long ta = min(n - wr + 1, x + 1);
    long tb = min(n - x, wl + 2);

    cout << max(ta, tb) << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2127/339323781
