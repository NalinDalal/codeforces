/*C. Raspberries
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array of integers 𝑎1,𝑎2,…,𝑎𝑛
 and a number 𝑘
 (2≤𝑘≤5
). In one operation, you can do the following:

Choose an index 1≤𝑖≤𝑛
,
Set 𝑎𝑖=𝑎𝑖+1
.
Find the minimum number of operations needed to make the product of all the
numbers in the array 𝑎1⋅𝑎2⋅…⋅𝑎𝑛 divisible by 𝑘
.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. Then follows the description of
the test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤105
, 2≤𝑘≤5
) — the size of the array 𝑎
 and the number 𝑘
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤10
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum number of operations needed to make the
product of all the numbers in the array divisible by 𝑘
.

Example
InputCopy
15
2 5
7 3
3 3
7 4 1
5 2
9 7 7 3 9
5 5
5 4 1 2 3
7 4
9 5 1 5 9 5 1
3 4
6 3 6
3 4
6 1 5
3 4
1 5 9
4 4
1 4 1 1
3 4
3 5 3
4 5
8 9 9 3
2 5
1 6
2 5
10 10
4 5
1 6 1 1
2 5
7 7
OutputCopy
2
2
1
0
2
0
1
2
0
1
1
4
0
4
3
Note
In the first test case, we need to choose the index 𝑖=2
 twice. After that, the array will be 𝑎=[7,5]
. The product of all the numbers in the array is 35
.

In the fourth test case, the product of the numbers in the array is 120
, which is already divisible by 5
, so no operations are needed.

In the eighth test case, we can perform two operations by choosing 𝑖=2
 and 𝑖=3
 in any order. After that, the array will be 𝑎=[1,6,10]
. The product of the numbers in the array is 60
.
*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n, k;
    std::cin >> n >> k;

    int maxRem = 0, evenCount = 0;
    bool divisible = false;

    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      x %= k;

      if (x == 0) {
        divisible = true;
      } else {
        maxRem = std::max(maxRem, x);
        if (x == 2) {
          ++evenCount;
        }
      }
    }

    if (divisible) {
      std::cout << 0 << std::endl;
    } else if (k == 4) {
      if (evenCount >= 2) {
        std::cout << 0 << std::endl;
      } else if (evenCount >= 1 || maxRem == 3) {
        std::cout << 1 << std::endl;
      } else {
        std::cout << 2 << std::endl;
      }
    } else {
      std::cout << k - maxRem << std::endl;
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1883/326097609
