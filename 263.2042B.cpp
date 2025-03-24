/*B. Game with Colored Marbles
time limit per test2 seconds
memory limit per test512 megabytes
Alice and Bob play a game. There are 𝑛
 marbles, the 𝑖
-th of them has color 𝑐𝑖
. The players take turns; Alice goes first, then Bob, then Alice again, then Bob
again, and so on.

During their turn, a player must take one of the remaining marbles and remove it
from the game. If there are no marbles left (all 𝑛 marbles have been taken), the
game ends.

Alice's score at the end of the game is calculated as follows:

she receives 1
 point for every color 𝑥
 such that she has taken at least one marble of that color;
additionally, she receives 1
 point for every color 𝑥
 such that she has taken all marbles of that color (of course, only colors
present in the game are considered). For example, suppose there are 5 marbles,
their colors are [1,3,1,3,4] , and the game goes as follows: Alice takes the 1
-st marble, then Bob takes the 3
-rd marble, then Alice takes the 5
-th marble, then Bob takes the 2
-nd marble, and finally, Alice takes the 4
-th marble. Then, Alice receives 4
 points: 3
 points for having at least one marble for colors 1
, 3
 and 4
, and 1
 point for having all marbles of color 4
. Note that this strategy is not necessarily optimal for both players.

Alice wants to maximize her score at the end of the game. Bob wants to minimize
it. Both players play optimally (i. e. Alice chooses a strategy which allows her
to get as many points as possible, and Bob chooses a strategy which minimizes
the amount of points Alice can get).

Calculate Alice's score at the end of the game.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer 𝑛
 (1≤𝑛≤1000
) — the number of marbles;
the second line contains 𝑛
 integers 𝑐1,𝑐2,…,𝑐𝑛
 (1≤𝑐𝑖≤𝑛
) — the colors of the marbles.
Additional constraint on the input: the sum of 𝑛
 over all test cases does not exceed 1000
.

Output
For each test case, print one integer — Alice's score at the end of the game,
assuming that both players play optimally.

Example
InputCopy
3
5
1 3 1 3 4
3
1 2 3
4
4 4 4 4
OutputCopy
4
4
1
Note
In the second test case of the example, the colors of all marbles are distinct,
so, no matter how the players act, Alice receives 4 points for having all
marbles of two colors, and no marbles of the third color.

In the third test case of the example, the colors of all marbles are the same,
so, no matter how the players act, Alice receives 1 point for having at least
one (but not all) marble of color 4.
*/

#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> m;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ++m[x];
    }
    int ones = 0, more = 0;
    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
      int cnt = it->second;
      if (cnt == 1) {
        ++ones;
      } else {
        ++more;
      }
    }
    cout << 2 * ((ones + 1) / 2) + more << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2042/312134042
