/*B. Fancy Coins
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp is going to make a purchase with cost of exactly 𝑚
 burles.

He has two types of coins, in the following quantities:

coins worth 1
 burle: 𝑎1
 regular coins and infinitely many fancy coins;
coins worth 𝑘
 burles: 𝑎𝑘
 regular coins and infinitely many fancy coins.
Monocarp wants to make his purchase in such a way that there's no change — the
total worth of provided coins is exactly 𝑚 . He can use both regular and fancy
coins. However, he wants to spend as little fancy coins as possible.

What's the smallest total number of fancy coins he can use to make a purchase?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤3⋅104
) — the number of testcases.

The only line of each testcase contains four integers 𝑚,𝑘,𝑎1
 and 𝑎𝑘
 (1≤𝑚≤108
; 2≤𝑘≤108
; 0≤𝑎1,𝑎𝑘≤108
) — the cost of the purchase, the worth of the second type of coin and the
amounts of regular coins of both types, respectively.

Output
For each testcase, print a single integer — the smallest total number of fancy
coins Monocarp can use to make a purchase.

Example
InputCopy
4
11 3 0 0
11 3 20 20
11 3 6 1
100000000 2 0 0
OutputCopy
5
0
1
50000000
Note
In the first testcase, there are no regular coins of either type. Monocarp can
use 2 fancy coins worth 1 burle and 3 fancy coins worth 3 (since 𝑘=3 ) burles to
get 11 total burles with 5 total fancy coins.

In the second testcase, Monocarp has a lot of regular coins of both types. He
can use 11 regular coins worth 1 burle, for example. Notice that Monocarp
doesn't have to minimize the total number of used coins. That way he uses 0
 fancy coins.

In the third testcase, Monocarp can use 5
 regular coins worth 1
 burle and 1
 regular coin worth 3
 burles. That will get him to 8
 total burles when he needs 11
. So, 1
 fancy coin worth 3
 burles is enough.
*/

#include <iostream>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long m, k, a, b;
    std::cin >> m >> k >> a >> b;

    long x = m / k;
    long rs = m % k;
    long fs = rs - a;
    fs = (fs > 0) ? fs : 0;
    long ls = a - rs;
    ls = (ls > 0) ? ls : 0;
    long fk = x - b;
    fk = (fk > 0) ? fk : 0;
    long cnt = fs + fk - ((ls / k < fk) ? (ls / k) : fk);
    std::cout << cnt << '\n';
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1860/334000609
