/*A. Card Exchange
time limit per test1 second
memory limit per test256 megabytes
You have a hand of 𝑛
 cards, where each card has a number written on it, and a fixed integer 𝑘
. You can perform the following operation any number of times:

Choose any 𝑘
 cards from your hand that all have the same number.
Exchange these cards for 𝑘−1
 cards, each of which can have any number you choose (including the number
written on the cards you just exchanged). Here is one possible sequence of
operations for the first example case, which has 𝑘=3
:


What is the minimum number of cards you can have in your hand at the end of this
process?

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤500
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤100
, 2≤𝑘≤100
) — the number of cards you have, and the number of cards you exchange during
each operation, respectively.

The next line of each test case contains 𝑛
 integers 𝑐1,𝑐2,…𝑐𝑛
 (1≤𝑐𝑖≤100
) — the numbers written on your cards.

Output
For each test case, output a single integer — the minimum number of cards you
can have left in your hand after any number of operations.

Example
InputCopy
7
5 3
4 1 1 4 4
1 10
7
7 2
4 2 1 100 5 2 3
10 4
1 1 1 1 1 1 1 1 1 1
5 2
3 8 1 48 7
6 2
10 20 30 10 20 40
6 3
10 20 30 10 20 40
OutputCopy
2
1
1
3
5
1
6
Note
The first example case corresponds to the picture above. The sequence of
operations displayed there is optimal, so the answer is 2
.

In the second example case, no operations can be performed, so the answer is 1
.

In the fourth example case, you can repeatedly select 4
 cards numbered with 1
 and replace them with 3
 cards numbered with 1
, until there are 3
 cards left.
*/

#include <iostream>
#include <map>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n, k;
    std::cin >> n >> k;
    std::map<long, long> m;
    bool reached = false;
    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;
      ++m[x];
      if (m[x] >= k) {
        reached = true;
      }
    }

    std::cout << (reached ? (k - 1) : n) << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1966/331427071
