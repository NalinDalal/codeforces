/*A. Catch the Coin
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp visited a retro arcade club with arcade cabinets. There got curious
about the "Catch the Coin" cabinet.

The game is pretty simple. The screen represents a coordinate grid such that:

the X-axis is directed from left to right;
the Y-axis is directed from bottom to top;
the center of the screen has coordinates (0,0)
.
At the beginning of the game, the character is located in the center, and 𝑛
 coins appear on the screen — the 𝑖
-th coin is at coordinates (𝑥𝑖,𝑦𝑖)
. The coordinates of all coins are different and not equal to (0,0)
.

In one second, Monocarp can move the character in one of eight directions. If
the character is at coordinates (𝑥,𝑦) , then it can end up at any of the
coordinates (𝑥,𝑦+1) , (𝑥+1,𝑦+1) , (𝑥+1,𝑦) , (𝑥+1,𝑦−1) , (𝑥,𝑦−1) , (𝑥−1,𝑦−1) ,
(𝑥−1,𝑦) , (𝑥−1,𝑦+1)
.

If the character ends up at the coordinates with a coin, then Monocarp collects
that coin.

After Monocarp makes a move, all coins fall down by 1
, that is, they move from (𝑥,𝑦)
 to (𝑥,𝑦−1)
. You can assume that the game field is infinite in all directions.

Monocarp wants to collect at least one coin, but cannot decide which coin to go
for. Help him determine, for each coin, whether he can collect it.

Input
The first line contains a single integer 𝑛
 (1≤𝑛≤500
) — the number of coins.

In the 𝑖
-th of the next 𝑛
 lines, two integers 𝑥𝑖
 and 𝑦𝑖
 (−50≤𝑥𝑖,𝑦𝑖≤50
) are written — the coordinates of the 𝑖
-th coin. The coordinates of all coins are different. No coin is located at
(0,0)
.

Output
For each coin, print "YES" if Monocarp can collect it. Otherwise, print "NO".

Example
InputCopy
5
24 42
-2 -1
-1 -2
0 -50
15 0
OutputCopy
YES
YES
NO
NO
YES
Note
Pay attention to the second coin in the example. Monocarp can first move from
(0,0) to (−1,−1) . Then the coin falls 1 down and ends up at (−2,−2) . Finally,
Monocarp moves to (−2,−2) and collects the coin.
*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int x, y;
    std::cin >> x >> y;
    std::cout << (y >= -1 ? "YES" : "NO") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1989/327965129
