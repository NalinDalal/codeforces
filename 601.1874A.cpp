/*A. Jellyfish and Game
time limit per test1 second
memory limit per test256 megabytes
Jellyfish has 𝑛
 green apples with values 𝑎1,𝑎2,…,𝑎𝑛
 and Gellyfish has 𝑚
 green apples with values 𝑏1,𝑏2,…,𝑏𝑚
.

They will play a game with 𝑘
 rounds. For 𝑖=1,2,…,𝑘
 in this order, they will perform the following actions:

If 𝑖
 is odd, Jellyfish can choose to swap one of her apples with one of Gellyfish's
apples or do nothing. If 𝑖 is even, Gellyfish can choose to swap one of his
apples with one of Jellyfish's apples or do nothing. Both players want to
maximize the sum of the values of their apples.

Since you are one of the smartest people in the world, Jellyfish wants you to
tell her the final sum of the value of her apples after all 𝑘 rounds of the
game. Assume that both Jellyfish and Gellyfish play optimally to maximize the
sum of values of their apples.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤2000
). The description of the test cases follows.

The first line of each test case contains three integers, 𝑛
, 𝑚
 and 𝑘
 (1≤𝑛,𝑚≤50
, 1≤𝑘≤109
) — the number of green apples Jellyfish has, the number of green apples
Gellyfish has and the number of rounds of the game respectively.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the values of Jellyfish's green apples.

The third line of each test case contains 𝑚
 integers 𝑏1,𝑏2,…,𝑏𝑚
 (1≤𝑏𝑖≤109
) — the values of Gellyfish's green apples.

Do note that the sum of 𝑛
 and 𝑚
 over all test cases are both not bounded.

Output
For each test case, output a single integer — the final sum of the values of
Jellyfish's apples.

Example
InputCopy
4
2 2 1
1 2
3 4
1 1 10000
1
2
4 5 11037
1 1 4 5
1 9 1 9 8
1 1 1
2
1
OutputCopy
6
1
19
2
Note
In the first test case, Jellyfish will swap the apple of value 1
 and 4
.

In the second test case, both players will swap the two apples 10,000
 times.

In the fourth test case, Jellyfish will do nothing.
*/

#include <algorithm>
#include <iostream>
typedef long long ll;

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n, m, k;
    std::cin >> n >> m >> k;
    long amn(1e9 + 7), amx(0), bmn(1e9 + 7), bmx(0);
    long long sa(0);
    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;
      sa += x;
      amn = std::min(amn, x);
      amx = std::max(amx, x);
    }

    for (long p = 0; p < m; p++) {
      long x;
      std::cin >> x;
      bmn = std::min(bmn, x);
      bmx = std::max(bmx, x);
    }

    if (bmx > amn) {
      sa += (bmx - amn);
    }
    if (k % 2 == 0) {
      sa += (std::min(bmn, amn) - std::max(bmx, amx));
    }
    std::cout << sa << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1874/334147748
