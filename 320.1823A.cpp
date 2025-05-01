/*A. A-characteristic
time limit per test1 second
memory limit per test256 megabytes
Consider an array 𝑎1,𝑎2,…,𝑎𝑛
 consisting of numbers 1
 and −1
. Define 𝐴
-characteristic of this array as a number of pairs of indices 1≤𝑖<𝑗≤𝑛
, such that 𝑎𝑖⋅𝑎𝑗=1
.

Find any array 𝑎
 with given length 𝑛
 with 𝐴
-characteristic equal to the given value 𝑘
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100
). The description of the test cases follows.

The only line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤100
; 0≤𝑘≤(𝑛−1)𝑛2
) — the length of required array and required 𝐴
-characteristic.

Output
For each test case, if there is no array 𝑎
 with given 𝐴
-characteristic 𝑘
, print NO.

Otherwise, print YES and 𝑛
 numbers 1
 and −1
, which form the required array 𝑎
. If there are multiple answers, print any of them.

Example
InputCopy
7
2 0
2 1
3 1
3 2
3 3
5 4
5 5
OutputCopy
YES
1 -1
YES
1 1
YES
1 -1 1
NO
YES
1 1 1
YES
-1 1 -1 1 1
NO
Note
In the first test case, there is only one pair of different elements in the
array, and their product is 𝑎1⋅𝑎2=−1≠1 , hence its 𝐴 -characteristic is 0
.

In the second test case, there is only one pair of different elements in the
array, and their product is 𝑎1⋅𝑎2=1 , hence its 𝐴 -characteristic is 1
.

In the third test case, there are three pairs of different elements in the
array, and their product are: 𝑎1⋅𝑎2=−1 , 𝑎1⋅𝑎3=1 , 𝑎2⋅𝑎3=−1 , hence its 𝐴
-characteristic is 1
.

In the fourth test case, we can show, that there is no array with length 3
, which 𝐴
-characteristic is 2
.
*/
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n, k;
    std::cin >> n >> k;

    long same = -1;
    for (long p = 0; 2 * p <= n; p++) {
      long tst = p * (p - 1) / 2 + (n - p) * (n - p - 1) / 2;
      if (tst == k) {
        same = p;
        break;
      }
    }

    if (same < 0) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      for (long p = 0; p < n; p++) {
        std::cout << (p < same ? 1 : -1) << " ";
      }
      std::cout << "\n";
    }
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1823/317898408
