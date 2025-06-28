/*B. Array Craft
time limit per test1 second
memory limit per test256 megabytes
For an array 𝑏
 of size 𝑚
, we define:

the maximum prefix position of 𝑏
 is the smallest index 𝑖
 that satisfies 𝑏1+…+𝑏𝑖=max𝑚𝑗=1(𝑏1+…+𝑏𝑗)
;
the maximum suffix position of 𝑏
 is the largest index 𝑖
 that satisfies 𝑏𝑖+…+𝑏𝑚=max𝑚𝑗=1(𝑏𝑗+…+𝑏𝑚)
.
You are given three integers 𝑛
, 𝑥
, and 𝑦
 (𝑥>𝑦
). Construct an array 𝑎
 of size 𝑛
 satisfying:

𝑎𝑖
 is either 1
 or −1
 for all 1≤𝑖≤𝑛
;
the maximum prefix position of 𝑎
 is 𝑥
;
the maximum suffix position of 𝑎
 is 𝑦
.
If there are multiple arrays that meet the conditions, print any. It can be
proven that such an array always exists under the given conditions.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

For each test case:

The only line contains three integers 𝑛
, 𝑥
, and 𝑦
 (2≤𝑛≤105,1≤𝑦<𝑥≤𝑛)
.
It is guaranteed that the sum of 𝑛
 over all test cases will not exceed 105
.

Output
For each test case, output 𝑛
 space-separated integers 𝑎1,𝑎2,…,𝑎𝑛
 in a new line.

Example
InputCopy
3
2 2 1
4 4 3
6 5 1
OutputCopy
1 1
1 -1 1 1
1 1 -1 1 1 -1
Note
In the second test case,

𝑖=𝑥=4
 is the smallest index that satisfies 𝑎1+…+𝑎𝑖=max𝑛𝑗=1(𝑎1+…+𝑎𝑗)=2
;
𝑖=𝑦=3
 is the greatest index that satisfies 𝑎𝑖+…+𝑎𝑛=max𝑛𝑗=1(𝑎𝑗+…+𝑎𝑛)=2
.
Thus, the array 𝑎=[1,−1,1,1]
 is considered correct.



*/
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long n, x, y;
    std::cin >> n >> x >> y;

    for (long p = 1; p <= n; ++p) {
      if (p < y) {
        std::cout << ((p % 2 == y % 2) ? 1 : -1) << ' ';
      } else if (p <= x) {
        std::cout << "1 ";
      } else {
        std::cout << ((p % 2 == x % 2) ? 1 : -1) << ' ';
      }
    }
    std::cout << '\n';
  }
}
// sub: https://codeforces.com/problemset/submission/1990/326439730
