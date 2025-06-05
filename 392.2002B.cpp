/* B. Removals Game
time limit per test1 second
memory limit per test256 megabytes
Alice got a permutation 𝑎1,𝑎2,…,𝑎𝑛
 of [1,2,…,𝑛]
, and Bob got another permutation 𝑏1,𝑏2,…,𝑏𝑛
 of [1,2,…,𝑛]
. They are going to play a game with these arrays.

In each turn, the following events happen in order:

Alice chooses either the first or the last element of her array and removes it
from the array; Bob chooses either the first or the last element of his array
and removes it from the array. The game continues for 𝑛−1 turns, after which
both arrays will have exactly one remaining element: 𝑥 in the array 𝑎 and 𝑦 in
the array 𝑏
.

If 𝑥=𝑦
, Bob wins; otherwise, Alice wins. Find which player will win if both players
play optimally.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤3⋅105
).

The next line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
, all 𝑎𝑖
 are distinct) — the permutation of Alice.

The next line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤𝑛
, all 𝑏𝑖
 are distinct) — the permutation of Bob.

It is guaranteed that the sum of all 𝑛
 does not exceed 3⋅105
.

Output
For each test case, print a single line with the name of the winner, assuming
both players play optimally. If Alice wins, print 𝙰𝚕𝚒𝚌𝚎 ; otherwise, print 𝙱𝚘𝚋
.

Example
InputCopy
2
2
1 2
1 2
3
1 2 3
2 3 1
OutputCopy
Bob
Alice
Note
In the first test case, Bob can win the game by deleting the same element as
Alice did.

In the second test case, Alice can delete 3
 in the first turn, and then in the second turn, delete the element that is
different from the one Bob deleted in the first turn to win the game.


*/

#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;

    std::vector<long> a(n);
    for (long p = 0; p < n; ++p) {
      std::cin >> a[p];
    }

    bool fs = true, fr = true;
    for (long p = 0; p < n; ++p) {
      long b;
      std::cin >> b;
      if (b != a[p]) {
        fs = false;
      }
      if (b != a[n - 1 - p]) {
        fr = false;
      }
    }

    std::cout << (fs || fr ? "Bob" : "Alice") << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2002/322997492
