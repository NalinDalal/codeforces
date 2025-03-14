/* A. Two Vessels
time limit per test1 second
memory limit per test256 megabytes
You have two vessels with water. The first vessel contains 𝑎
 grams of water, and the second vessel contains 𝑏
 grams of water. Both vessels are very large and can hold any amount of water.

You also have an empty cup that can hold up to 𝑐
 grams of water.

In one move, you can scoop up to 𝑐
 grams of water from any vessel and pour it into the other vessel. Note that the
mass of water poured in one move does not have to be an integer.

What is the minimum number of moves required to make the masses of water in the
vessels equal? Note that you cannot perform any actions other than the described
moves.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

Each test case consists of a single line containing three integers 𝑎
, 𝑏
, and 𝑐
 (1≤𝑎,𝑏,𝑐≤100
) — the mass of water in the vessels and the capacity of the cup, respectively.

Output
For each test case, output a single number — the minimum number of moves
required to make the masses of water in the vessels equal. It can be shown, that
it is always possible.

Example
InputCopy
6
3 7 2
17 4 3
17 17 1
17 21 100
1 100 1
97 4 3
OutputCopy
1
3
0
1
50
16
Note
In the first test case, only one move is enough: if we pour 2
 grams of water from the second vessel into the first one, both vessels will
contain 5 grams of water.

In the second example test case, three moves are enough:

Pour 3
 grams of water from the first vessel into the second one. After this move, the
first vessel will contain 17−3=14 grams of water, and the second vessel will
contain 4+3=7 grams. Pour 2 grams of water from the first vessel into the second
one. After this move, the first vessel will contain 14−2=12 grams of water, and
the second vessel will contain 7+2=9 grams. Finally, pour 1.5 grams of water
from the first vessel into the second one. After this move, the first vessel
will contain 12−1.5=10.5 grams of water, and the second vessel will contain
9+1.5=10.5 grams. Note that this is not the only way to equalize the vessels in
3 moves, but there is no way to do it in 2 moves.

In the third example test case, the vessels initially contain the same amount of
water, so no moves are needed. The answer is 0
.


*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a > b) {
      std::swap(a, b);
    }
    int diff = (b - a + 1) / 2;
    int ans = (diff + c - 1) / c;
    std::cout << ans << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1872/310611547
