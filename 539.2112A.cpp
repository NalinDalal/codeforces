/*
 * A. Race
time limit per test2 seconds
memory limit per test256 megabytes
Alice and Bob participate in a game TV show. When the game starts, the prize
will be dropped to a certain point, and whoever gets to it first will get the
prize.

Alice decided that she would start running from point 𝑎
. Bob, however, has not yet chosen his starting position.

Bob knows that the prize could drop either at point 𝑥
 or at point 𝑦
. He also knows that he can reach the prize faster than Alice if the distance
from his starting position to the prize is strictly less than the distance from
Alice's starting position to the prize. The distance between any two points 𝑐
 and 𝑑
 is calculated as |𝑐−𝑑|
.

Your task is to determine whether Bob can choose an integer point that is
guarantee to get to the prize faster, regardless of where it appears (at point 𝑥
 or 𝑦
). Bob can choose any integer point, except for 𝑎
 (in particular, he can choose to start in point 𝑥
, point 𝑦
, or any other point, but not 𝑎
).

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The only line of each test case contains three integers 𝑎
, 𝑥
, 𝑦
 (1≤𝑎,𝑥,𝑦≤100
). Points 𝑎
, 𝑥
, and 𝑦
 are pairwise distinct.

Output
For each test case, print "YES" (case insensitive) if Bob can choose an integer
point that is guarantee to get to the prize faster, regardless of where it
appears. Otherwise, print "NO" (case insensitive).

Example
InputCopy
3
1 3 4
5 3 1
3 1 5
OutputCopy
YES
YES
NO
Note
In the first example, Bob can choose point 4
. If the prize will be at point 𝑥
, then Bob's distance is |4−3|=1
 and Alice's distance is |1−3|=2
. If the prize will be at point 𝑦
, then Bob's distance is |4−4|=0
 and Alice's distance is |1−4|=3
.

In the second example, Bob can choose point 2
. If the prize will be at point 𝑥
, then Bob's distance is |2−3|=1
 and Alice's distance is |5−3|=2
. If the prize will be at point 𝑦
, then Bob's distance is |2−1|=1
 and Alice's distance is |5−1|=4
.

In the third example, Bob cannot choose a point to guarantee his victory.
*/
#include <iostream>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long a, x, y;
    std::cin >> a >> x >> y;
    if (x > y) {
      long u = x;
      x = y;
      y = u;
    }
    std::cout << ((x <= a && a <= y) ? "NO" : "YES") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2112/331075755
