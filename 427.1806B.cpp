/*B. Mex Master
time limit per test1 second
memory limit per test1024 megabytes
You are given an array 𝑎
 of length 𝑛
. The score of 𝑎
 is the MEX†
 of [𝑎1+𝑎2,𝑎2+𝑎3,…,𝑎𝑛−1+𝑎𝑛]
. Find the minimum score of 𝑎
 if you are allowed to rearrange elements of 𝑎
 in any order. Note that you are not required to construct the array 𝑎
 that achieves the minimum score.

†
 The MEX (minimum excluded) of an array is the smallest non-negative integer
that does not belong to the array. For instance:

The MEX of [2,2,1]
 is 0
, because 0
 does not belong to the array.
The MEX of [3,1,0,1]
 is 2
, because 0
 and 1
 belong to the array, but 2
 does not.
The MEX of [0,3,1,2]
 is 4
 because 0
, 1
, 2
, and 3
 belong to the array, but 4
 does not.
Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
).

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤2⋅105
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum score of 𝑎
 after rearranging the elements of 𝑎
 in any order.

Example
InputCopy
3
2
0 0
3
0 0 1
8
1 0 0 0 2 0 3 0
OutputCopy
1
0
1
Note
In the first test case, it is optimal to rearrange 𝑎
 as [0,0]
, the score of this array is the MEX of [0+0]=[0]
, which is 1
.

In the second test case, it is optimal to rearrange 𝑎
 as [0,1,0]
, the score of this array is the MEX of [0+1,1+0]=[1,1]
, which is 0
.
*/

#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n;
    std::cin >> n;

    long z = 0;
    bool one = false, large = false;

    for (long p = 0; p < n; ++p) {
      long x;
      std::cin >> x;
      if (x == 0) {
        ++z;
      } else if (x == 1) {
        one = true;
      } else {
        large = true;
      }
    }

    long res = 0;
    if (z > (n + 1) / 2) {
      if (!one || large) {
        res = 1;
      } else {
        res = 2;
      }
    }

    std::cout << res << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1806/324989934
