/* B. Following Directions
time limit per test1 second
memory limit per test256 megabytes
Alperen is standing at the point (0,0)
. He is given a string 𝑠
 of length 𝑛
 and performs 𝑛
 moves. The 𝑖
-th move is as follows:

if 𝑠𝑖=𝙻
, then move one unit left;
if 𝑠𝑖=𝚁
, then move one unit right;
if 𝑠𝑖=𝚄
, then move one unit up;
if 𝑠𝑖=𝙳
, then move one unit down.
If Alperen starts at the center point, he can make the four moves shown.
There is a candy at (1,1)
 (that is, one unit above and one unit to the right of Alperen's starting
point). You need to determine if Alperen ever passes the candy. Alperen's path
in the first test case. Input The first line of the input contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of testcases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤50
) — the length of the string.

The second line of each test case contains a string 𝑠
 of length 𝑛
 consisting of characters 𝙻
, 𝚁
, 𝙳
, and 𝚄
, denoting the moves Alperen makes.

Output
For each test case, output "YES" (without quotes) if Alperen passes the candy,
and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes",
"Yes" and "YES" will be recognized as a positive answer).

Example
InputCopy
7
7
UUURDDL
2
UR
8
RRRUUDDD
3
LLL
4
DUUR
5
RUDLL
11
LLLLDDRUDRD
OutputCopy
YES
YES
NO
NO
YES
YES
NO
Note
In the first test case, Alperen follows the path
(0,0)→𝚄(0,1)→𝚄(0,2)→𝚄(0,3)→𝚁(1,3)→𝙳(1,2)→𝙳(1,1)→𝙻(0,1).
Note that Alperen doesn't need to end at the candy's location of (1,1)
, he just needs to pass it at some point.

In the second test case, Alperen follows the path
(0,0)→𝚄(0,1)→𝚁(1,1).

In the third test case, Alperen follows the path
(0,0)→𝚁(1,0)→𝚁(2,0)→𝚁(3,0)→𝚄(3,1)→𝚄(3,2)→𝙳(3,1)→𝙳(3,0)→𝙳(3,−1).

In the fourth test case, Alperen follows the path
(0,0)→𝙻(−1,0)→𝙻(−2,0)→𝙻(−3,0).


*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // maintain a set of point->{x,y}
    int x = 0, y = 0; // Start at (0,0)
    bool reached = false;

    for (int i = 0; i < n; i++) {
      if (s[i] == 'U')
        y++;
      else if (s[i] == 'D')
        y--;
      else if (s[i] == 'L')
        x--;
      else if (s[i] == 'R')
        x++;

      if (x == 1 && y == 1) {
        reached = true;

        break;
      }
    }
    if (reached)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1791/308175275
