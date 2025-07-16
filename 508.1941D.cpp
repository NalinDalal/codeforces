/*D. Rudolf and the Ball Game
time limit per test2 seconds
memory limit per test256 megabytes
Rudolf and Bernard decided to play a game with their friends. 𝑛
 people stand in a circle and start throwing a ball to each other. They are
numbered from 1 to 𝑛 in the clockwise order.

Let's call a transition a movement of the ball from one player to his neighbor.
The transition can be made clockwise or counterclockwise.

Let's call the clockwise (counterclockwise) distance from player 𝑦1
 to player 𝑦2
 the number of transitions clockwise (counterclockwise) that need to be made to
move from player 𝑦1 to player 𝑦2 . For example, if 𝑛=7 then the clockwise
distance from 2 to 5 is 3 , and the counterclockwise distance from 2 to 5 is 4
.

Initially, the ball is with the player number 𝑥
 (players are numbered clockwise). On the 𝑖
-th move the person with the ball throws it at a distance of 𝑟𝑖
 (1≤𝑟𝑖≤𝑛−1
) clockwise or counterclockwise. For example, if there are 7
 players, and the 2
nd player, after receiving the ball, throws it a distance of 5
, then the ball will be caught by either the 7
th player (throwing clockwise) or the 4
th player (throwing counterclockwise). An illustration of this example is shown
below.


The game was interrupted after 𝑚
 throws due to unexpected rain. When the rain stopped, the guys gathered again
to continue. However, no one could remember who had the ball. As it turned out,
Bernard remembered the distances for each of the throws and the direction for
some of the throws (clockwise or counterclockwise).

Rudolf asks you to help him and based on the information from Bernard, calculate
the numbers of the players who could have the ball after 𝑚 throws.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Then follow the descriptions of the test cases.

The first line of each test case contains three integers 𝑛,𝑚,𝑥
 (2≤𝑛≤1000
, 1≤𝑚≤1000
, 1≤𝑥≤𝑛
) — the number of players, the number of throws made, and the number of the
player who threw the ball first, respectively.

The next 𝑚
 lines contain information about each throw in order. Each of them contains an
integer 𝑟𝑖 (1≤𝑟𝑖≤𝑛−1 ) — the distance at which the 𝑖 -th throw was made, and a
symbol 𝑐𝑖 , equal to '0', '1', or '?':

if 𝑐𝑖
='0', then the 𝑖
-th throw was made clockwise,
if 𝑐𝑖
='1', then the 𝑖
-th throw was made counterclockwise,
if 𝑐𝑖
='?', then Bernard does not remember the direction and the 𝑖
-th throw could have been made either clockwise or counterclockwise.
It is guaranteed that the sum 𝑛⋅𝑚
 (𝑛
 multiplied by 𝑚
) over all test cases does not exceed 2⋅105
.

Output
For each test case, output two lines.

In the first line, output the number of players 𝑘
 (1≤𝑘≤𝑛
) who could have the ball at the end of the game.

In the next line, output 𝑘
 numbers 𝑏𝑖
 (1≤𝑏𝑖≤𝑛
) — the numbers of the players in increasing order. All numbers must be
different.

Example
InputCopy
5
6 3 2
2 ?
2 ?
2 ?
12 1 2
3 1
10 7 4
2 ?
9 1
4 ?
7 0
2 0
8 1
5 ?
5 3 1
4 0
4 ?
1 ?
4 1 1
2 ?
OutputCopy
3
2 4 6
1
11
4
3 5 7 9
3
2 3 5
1
3
Note
Below is an illustration of three throws for the first test case. The arrows
denote possible throw directions. Players who could have the ball after the
throw are highlighted in gray.
*/

#include <iostream>
#include <set>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n, m, x;
    std::cin >> n >> m >> x;
    std::set<long> s;
    s.insert(x - 1);
    for (long p = 0; p < m; p++) {
      long r;
      char d;
      std::cin >> r >> d;

      std::set<long> w;
      for (std::set<long>::iterator it = s.begin(); it != s.end(); it++) {
        const long u = *it;
        if (d == '0' || d == '?') {
          w.insert((u + r) % n);
        }
        if (d == '1' || d == '?') {
          w.insert((n + (u - r) % n) % n);
        }
      }
      s = w;
    }

    std::cout << s.size() << std::endl;
    for (std::set<long>::iterator it = s.begin(); it != s.end(); it++) {
      std::cout << (1 + *it) << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1941/329195572
