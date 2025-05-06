/* A. Chess For Three
time limit per test1 second
memory limit per test256 megabytes
Three friends gathered to play a few games of chess together.

In every game, two of them play against each other. The winner gets 2
 points while the loser gets 0
, and in case of a draw, both players get 1
 point each. Note that the same pair of players could have played any
non-negative number of times (possibly zero). It is also possible that no games
were played at all.

You've been told that their scores after all the games were played were 𝑝1
, 𝑝2
 and 𝑝3
. Additionally, it is guaranteed that 𝑝1≤𝑝2≤𝑝3
 holds.

Find the maximum number of draws that could have happened and print it. If there
isn't any way to obtain 𝑝1 , 𝑝2 and 𝑝3 as a result of a non-negative number of
games between the three players, print −1 instead.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains three integers 𝑝1
, 𝑝2
 and 𝑝3
 (0≤𝑝1≤𝑝2≤𝑝3≤30
) — the scores of the three players, sorted non-decreasingly.

Output
For each testcase, print one number — the maximum possible number of draws that
could've happened, or −1 if the scores aren't consistent with any valid set of
games and results.

Example
InputCopy
7
0 0 0
0 1 1
1 1 1
1 1 2
3 3 3
3 4 5
1 1 10
OutputCopy
0
1
-1
2
-1
6
2
Note
In the first example, no games were played at all, so no draws could occur
either.

For the second example, exactly one game occurred between the second and the
third player and it ended in draw, so the answer is 1
.

It's easy to see that there's no set of games achieving the scores in third
example, so the answer for it is −1
.


*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;

    // winner - 2
    // loser - 0
    // draw - 1
    // a<=b<=c
    /*  if (a == 0 && b == 0 && c == 0)
        cout << 0 << endl;
      else if (a == b && b == c)
        cout << -1 << endl;
      else if (a + b == c)
        cout << c << endl;*/
    // cout no of draws
    // if no way to get a,b,c then cout -1

    if ((a + b + c) % 2) {
      cout << -1 << endl;
      continue;
    }
    int x = (a + b + c) / 2;
    int y = a + b;
    cout << (x < y ? x : y) << endl;
  }
  return 0;
} // sub: https://codeforces.com/problemset/submission/1973/318594661
