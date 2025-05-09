/* A. Thorns and Coins
time limit per test1 second
memory limit per test512 megabytes
During your journey through computer universes, you stumbled upon a very
interesting world. It is a path with 𝑛 consecutive cells, each of which can
either be empty, contain thorns, or a coin. In one move, you can move one or two
cells along the path, provided that the destination cell does not contain thorns
(and belongs to the path). If you move to the cell with a coin, you pick it up.

Here, green arrows correspond to legal moves, and the red arrow corresponds to
an illegal move. You want to collect as many coins as possible. Find the maximum
number of coins you can collect in the discovered world if you start in the
leftmost cell of the path.

Input
The first line of input contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. Then the descriptions of the test cases follow.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
) — the length of the path.

The second line of each test case contains a string of 𝑛
 characters, the description of the path. The character '.' denotes an empty
cell, '@' denotes a cell with a coin, and '*' denotes a cell with thorns. It is
guaranteed that the first cell is empty.

Output
For each test case, output a single integer, the maximum number of coins you can
collect.

Example
InputCopy
3
10
.@@*@.**@@
5
.@@@@
15
.@@..@***..@@@*
OutputCopy
3
4
3
Note
The picture for the first example is in the problem statement.

Here is the picture for the second example:


And here is the picture for the third example:



*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    long cnt(0);
    for (long p = 1; p < s.size(); p++) {
      if (s[p - 1] == '*' && s[p] == '*') {
        break;
      }
      cnt += (s[p] == '@');
    }
    std::cout << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1932/318941539
