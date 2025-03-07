/* A. Rudolf and the Ticket
time limit per test1 second
memory limit per test256 megabytes
Rudolf is going to visit Bernard, and he decided to take the metro to get to
him. The ticket can be purchased at a machine that accepts exactly two coins,
the sum of which does not exceed 𝑘
.

Rudolf has two pockets with coins. In the left pocket, there are 𝑛
 coins with denominations 𝑏1,𝑏2,…,𝑏𝑛
. In the right pocket, there are 𝑚
 coins with denominations 𝑐1,𝑐2,…,𝑐𝑚
. He wants to choose exactly one coin from the left pocket and exactly one coin
from the right pocket (two coins in total).

Help Rudolf determine how many ways there are to select indices 𝑓
 and 𝑠
 such that 𝑏𝑓+𝑐𝑠≤𝑘
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. Then follows the description of each test case.

The first line of each test case contains three natural numbers 𝑛
, 𝑚
, and 𝑘
 (1≤𝑛,𝑚≤100,1≤𝑘≤2000
) — the number of coins in the left and right pockets, and the maximum sum of
two coins for the ticket payment at the counter, respectively.

The second line of each test case contains 𝑛
 integers 𝑏𝑖
 (1≤𝑏𝑖≤1000
) — the denominations of coins in the left pocket.

The third line of each test case contains 𝑚
 integers 𝑐𝑖
 (1≤𝑐𝑖≤1000
) — the denominations of coins in the right pocket.

Output
For each testcase, output a single integer — the number of ways Rudolf can
select two coins, taking one from each pocket, so that the sum of the coins does
not exceed 𝑘
.

Example
InputCopy
4
4 4 8
1 5 10 14
2 1 8 1
2 3 4
4 8
1 2 3
4 2 7
1 1 1 1
2 7
3 4 2000
1 1 1
1 1 1 1
OutputCopy
6
0
4
12
Note
Note that the pairs indicate the indices of the coins in the array, not their
denominations.

In the first test case, Rudolf can choose the following pairs of coins:
[1,1],[1,2],[1,4],[2,1],[2,2],[2,4]
.

In the second test case, Rudolf cannot choose one coin from each pocket in any
way, as the sum of any two elements from the first and second arrays will exceed
the value of 𝑘=4
.

In the third test case, Rudolf can choose: [1,1],[2,1],[3,1],[4,1]
.

In the fourth test case, Rudolf can choose any coin from the left pocket and any
coin from the right pocket.


*/

#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n, m, k;
    std::cin >> n >> m >> k;

    std::vector<long> b(n);
    for (long &x : b) {
      std::cin >> x;
    }

    std::vector<long> c(m);
    for (long &x : c) {
      std::cin >> x;
    }

    long total = 0;
    for (long i = 0; i < n; i++) {
      for (long j = 0; j < m; j++) {
        if (b[i] + c[j] <= k) {
          ++total;
        }
      }
    }

    std::cout << total << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1941/309380674
