/*B. Rakhsh's Revival
time limit per test1 second
memory limit per test256 megabytes
Rostam's loyal horse, Rakhsh, has seen better days. Once powerful and fast,
Rakhsh has grown weaker over time, struggling to even move. Rostam worries that
if too many parts of Rakhsh's body lose strength at once, Rakhsh might stop
entirely. To keep his companion going, Rostam decides to strengthen Rakhsh, bit
by bit, so no part of his body is too frail for too long.


Imagine Rakhsh's body as a line of spots represented by a binary string 𝑠
 of length 𝑛
, where each 0
 means a weak spot and each 1
 means a strong one. Rostam's goal is to make sure that no interval of 𝑚
 consecutive spots is entirely weak (all 0
s).

Luckily, Rostam has a special ability called Timar, inherited from his mother
Rudabeh at birth. With Timar, he can select any segment of length 𝑘 and
instantly strengthen all of it (changing every character in that segment to 1
). The challenge is to figure out the minimum number of times Rostam needs to
use Timar to keep Rakhsh moving, ensuring there are no consecutive entirely weak
spots of length 𝑚
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
), the number of test cases.

The first line of each test case contains three numbers 𝑛
, 𝑚
, 𝑘
 (1≤𝑚,𝑘≤𝑛≤2⋅105
). The second line of each test case contains a binary string 𝑠
 of 𝑛
 characters 𝑠1𝑠2…𝑠𝑛
. (𝑠𝑖∈{
0,1}
 for 1≤𝑖≤𝑛
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum number of times Rostam needs to use Timar
to keep Rakhsh moving, ensuring there are no consecutive entirely weak spots of
length 𝑚
.

Example
InputCopy
3
5 1 1
10101
5 2 1
10101
6 3 2
000000
OutputCopy
2
0
1
Note
In the first test case, we should apply an operation on each 0.

In the second test case, 𝑠
 is already ok.

In the third test case, we can perform an operation on interval [3,4]
 to get 001100.
*/
#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n, m, k;
    std::cin >> n >> m >> k;
    std::string s;
    std::cin >> s;
    long z(0), cnt(0), cov(-1);
    for (long p = 0; p < n; p++) {
      if (s[p] == '1' || p <= cov) {
        z = 0;
        continue;
      }
      ++z;
      if (z >= m) {
        ++cnt;
        cov = p + k - 1;
        z = 0;
      }
    }

    std::cout << cnt << std::endl;
  }
  return 0;
} // sub: https://codeforces.com/problemset/submission/2034/331427335
