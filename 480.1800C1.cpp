/*C1. Powering the Hero (easy version)
time limit per test2 seconds
memory limit per test256 megabytes
This is an easy version of the problem. It differs from the hard one only by
constraints on 𝑛 and 𝑡
.

There is a deck of 𝑛
 cards, each of which is characterized by its power. There are two types of
cards:

a hero card, the power of such a card is always equal to 0
;
a bonus card, the power of such a card is always positive.
You can do the following with the deck:

take a card from the top of the deck;
if this card is a bonus card, you can put it on top of your bonus deck or
discard; if this card is a hero card, then the power of the top card from your
bonus deck is added to his power (if it is not empty), after that the hero is
added to your army, and the used bonus discards. Your task is to use such
actions to gather an army with the maximum possible total power.

Input
The first line of input data contains single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases in the test.

The first line of each test case contains one integer 𝑛
 (1≤𝑛≤5000
) — the number of cards in the deck.

The second line of each test case contains 𝑛
 integers 𝑠1,𝑠2,…,𝑠𝑛
 (0≤𝑠𝑖≤109
) — card powers in top-down order.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 5000
.

Output
Output 𝑡
 numbers, each of which is the answer to the corresponding test case — the
maximum possible total power of the army that can be achieved.

Example
InputCopy
5
5
3 3 3 0 0
6
0 3 3 0 0 3
7
1 2 3 0 4 5 0
7
1 2 5 0 4 3 0
5
3 1 0 0 4
OutputCopy
6
6
8
9
4
Note
In the first sample, you can take bonuses 1
 and 2
. Both hero cards will receive 3
 power. If you take all the bonuses, one of them will remain unused.

In the second sample, the hero's card on top of the deck cannot be powered up,
and the rest can be powered up with 2 and 3 bonuses and get 6 total power.

In the fourth sample, you can take bonuses 1
, 2
, 3
, 5
 and skip the bonus 6
, then the hero 4
 will be enhanced with a bonus 3
 by 5
, and the hero 7
 with a bonus 5
 by 4
. 4+5=9
.
*/

#include <iostream>
#include <queue>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::priority_queue<long> ds;
    long long res(0);
    for (long p = 0; p < n; p++) {
      long long x;
      std::cin >> x;
      if (x) {
        ds.push(x);
      } else if (!ds.empty()) {
        res += ds.top();
        ds.pop();
      }
    }
    std::cout << res << std::endl;
  }
}

// sub: https://codeforces.com/problemset/submission/1800/327965608
