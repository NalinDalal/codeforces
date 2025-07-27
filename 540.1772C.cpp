/*C. Different Differences
time limit per test2 seconds
memory limit per test512 megabytes
An array 𝑎
 consisting of 𝑘
 integers is strictly increasing if 𝑎1<𝑎2<⋯<𝑎𝑘
. For example, the arrays [1,3,5]
, [1,2,3,4]
, [3,5,6]
 are strictly increasing; the arrays [2,2]
, [3,7,5]
, [7,4,3]
, [1,2,2,3]
 are not.

For a strictly increasing array 𝑎
 of 𝑘
 elements, let's denote the characteristic as the number of different elements
in the array [𝑎2−𝑎1,𝑎3−𝑎2,…,𝑎𝑘−𝑎𝑘−1] . For example, the characteristic of the
array [1,3,4,7,8] is 3 since the array [2,1,3,1] contains 3 different elements:
2 , 1 and 3
.

You are given two integers 𝑘
 and 𝑛
 (𝑘≤𝑛
). Construct an increasing array of 𝑘
 integers from 1
 to 𝑛
 with maximum possible characteristic.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤819
) — the number of test cases.

Each test case consists of one line containing two integers 𝑘
 and 𝑛
 (2≤𝑘≤𝑛≤40
).

Output
For each test case, print 𝑘
 integers — the elements of the strictly increasing array 𝑎
 with the maximum possible characteristic. If there are multiple answers, print
any of them.

Example
InputCopy
7
5 9
4 12
3 3
3 4
4 4
4 6
8 11
OutputCopy
1 3 4 7 8
2 4 7 12
1 2 3
1 3 4
1 2 3 4
2 4 5 6
1 2 3 5 6 7 8 11
*/
#include <iostream>
#include <vector>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long k, n;
    std::cin >> k >> n;
    std::vector<long> a(k + 1);
    a[1] = 1;
    long d = 1;
    for (long p = 2; p <= k; p++) {
      if (d < 0) {
        a[p] = a[p - 1] + 1;
        continue;
      }
      long x = a[p - 1] + d;
      if (n - x < k - p) {
        a[p] = a[p - 1] + 1;
        d = -1;
      } else {
        a[p] = x;
        ++d;
      }
    }

    for (long p = 1; p <= k; p++) {
      std::cout << a[p] << " ";
    }
    std::cout << std::endl;
  }
  return 0;

  // sub: https://codeforces.com/problemset/submission/1772/331076020}
