/* moved to 900
https://codeforces.com/problemset/problem/1904/A

A. Forked!
time limit per test2 seconds
memory limit per test256 megabytes
Lunchbox is done with playing chess! His queen and king just got forked again!

In chess, a fork is when a knight attacks two pieces of higher value, commonly
the king and the queen. Lunchbox knows that knights can be tricky, and in the
version of chess that he is playing, knights are even trickier: instead of
moving 1 tile in one direction and 2 tiles in the other, knights in Lunchbox's
modified game move 𝑎 tiles in one direction and 𝑏 tiles in the other.

Lunchbox is playing chess on an infinite chessboard which contains all cells
(𝑥,𝑦) where 𝑥 and 𝑦 are (possibly negative) integers. Lunchbox's king and queen
are placed on cells (𝑥𝐾,𝑦𝐾) and (𝑥𝑄,𝑦𝑄) respectively. Find the number of
positions such that if a knight was placed on that cell, it would attack both
the king and queen.

Input
Each test contains multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers 𝑎
 and 𝑏
 (1≤𝑎,𝑏≤108
) — describing the possible moves of the knight.

The second line of each test case contains two integers 𝑥𝐾
 and 𝑦𝐾
 (0≤𝑥𝐾,𝑦𝐾≤108
) — the position of Lunchbox's king.

The third line in a test case contains 𝑥𝑄
 and 𝑦𝑄
 (0≤𝑥𝑄,𝑦𝑄≤108
) — the position of Lunchbox's queen.

It is guaranteed that Lunchbox's queen and king will occupy different cells.
That is, (𝑥𝐾,𝑦𝐾)≠(𝑥𝑄,𝑦𝑄)
.

Output
For each test case, output the number of positions on an infinite chessboard
such that a knight can attack both the king and the queen.

Example
InputCopy
4
2 1
0 0
3 3
1 1
3 1
1 3
4 4
0 0
8 0
4 2
1 4
3 4
OutputCopy
2
1
2
0
Note
In the first test case, the knight can move 2 squares in one direction and 1
square in the other (it is essentially the same as the knight in standard
chess). A knight placed on (2,1) or (1,2) would attack both the king and queen.

Example of a knight placement that forks the queen and king in the first test
case. The squares that the knight attacks are highlighted in red. In the second
test case, a knight placed on (2,2) would attack both the king and queen.

Example of a knight placement that does not fork the queen and king in the
second test case. The knight attacks the king but not the queen. In the third
test case, a knight placed on (4,4) or (4,−4) would attack both the king and
queen.

In the fourth test case, there are no positions where the knight can attack both
the king and the queen.*/

#include <bits/stdc++.h>

using namespace std;

int solve() {
  int a, b; // knight moves
  cin >> a >> b;
  int xK, yK; // king position
  cin >> xK >> yK;
  int xQ, yQ; // queen position
  cin >> xQ >> yQ;

  // cout the number of postion where knight can attack both king and queen
  set<pair<int, int>> s, t;

  // Possible knight moves from the king's position
  s.insert({xK + a, yK + b});
  s.insert({xK - a, yK + b});
  s.insert({xK + a, yK - b});
  s.insert({xK - a, yK - b});
  s.insert({xK + b, yK + a});
  s.insert({xK - b, yK + a});
  s.insert({xK + b, yK - a});
  s.insert({xK - b, yK - a});

  // Possible knight moves from the queen's position
  t.insert({xQ + a, yQ + b});
  t.insert({xQ - a, yQ + b});
  t.insert({xQ + a, yQ - b});
  t.insert({xQ - a, yQ - b});
  t.insert({xQ + b, yQ + a});
  t.insert({xQ - b, yQ + a});
  t.insert({xQ + b, yQ - a});
  t.insert({xQ - b, yQ - a});

  // Count intersections
  int cnt = 0;
  for (auto it : s) {
    cnt += t.count(it);
  }

  cout << cnt << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1904/302243844
