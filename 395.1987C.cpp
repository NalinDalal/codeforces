/*C. Basil's Garden
time limit per test2 seconds
memory limit per test256 megabytes
There are 𝑛
 flowers in a row, the 𝑖
-th of them initially has a positive height of ℎ𝑖
 meters.

Every second, the wind will blow from the left, causing the height of some
flowers to decrease.

Specifically, every second, for each 𝑖
 from 1
 to 𝑛
, in this order, the following happens:

If 𝑖=𝑛
 or ℎ𝑖>ℎ𝑖+1
, the value of ℎ𝑖
 changes to max(0,ℎ𝑖−1)
.
How many seconds will pass before ℎ𝑖=0
 for all 1≤𝑖≤𝑛
 for the first time?

Input
Each test contains multiple test cases. The first line of input contains a
single integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the
test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the number of flowers.

The second line of each test case contains 𝑛
 integers ℎ1,ℎ2,…,ℎ𝑛
 (1≤ℎ𝑖≤109
) — the heights of the flowers.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output a single integer — the number of seconds that will
pass before ℎ𝑖=0 for all 1≤𝑖≤𝑛
.

Example
InputCopy
4
3
1 1 2
2
3 1
1
9
5
7 4 4 3 2
OutputCopy
4
3
9
7
Note
In the first test case, the flower heights change as follows:
[1,1,2]→[1,1,1]→[1,1,0]→[1,0,0]→[0,0,0]
.

In the second test case, the flower heights change as follows:
[3,1]→[2,0]→[1,0]→[0,0]
.



*/

#include <iostream>
#include <vector>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> h(n);
    for (long p = 0; p < n; p++) {
      std::cin >> h[p];
    }
    long cnt(h.back());
    for (long p = n - 2; p >= 0; p--) {
      long tmp = cnt + 1;
      cnt = (tmp > h[p] ? tmp : h[p]);
    }
    std::cout << cnt << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1987/323093278
