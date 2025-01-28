/* https://codeforces.com/problemset/problem/1726/A
A. Mainak and Array
time limit per test1 second
memory limit per test256 megabytes
Mainak has an array 𝑎1,𝑎2,…,𝑎𝑛
 of 𝑛
 positive integers. He will do the following operation to this array exactly
once:

Pick a subsegment of this array and cyclically rotate it by any amount.
Formally, he can do the following exactly once:
Pick two integers 𝑙
 and 𝑟
, such that 1≤𝑙≤𝑟≤𝑛
, and any positive integer 𝑘
.
Repeat this 𝑘
 times: set 𝑎𝑙=𝑎𝑙+1,𝑎𝑙+1=𝑎𝑙+2,…,𝑎𝑟−1=𝑎𝑟,𝑎𝑟=𝑎𝑙
 (all changes happen at the same time).
Mainak wants to maximize the value of (𝑎𝑛−𝑎1)
 after exactly one such operation. Determine the maximum value of (𝑎𝑛−𝑎1)
 that he can obtain.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤50 ) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤2000).

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤999).

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2000.

Output
For each test case, output a single integer — the maximum value of (𝑎𝑛−𝑎1) that
Mainak can obtain by doing the operation exactly once.

Example
InputCopy
5
6
1 3 9 11 5 7
1
20
3
9 99 999
4
2 1 8 1
3
2 1 5
OutputCopy
10
0
990
7
4
Note
In the first test case, we can rotate the subarray from index 3
 to index 6
 by an amount of 2
 (i.e. choose 𝑙=3
, 𝑟=6
 and 𝑘=2
) to get the optimal array:
[1,3,9,11,5,7⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯]⟶[1,3,5,7,9,11⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯]
So the answer is 𝑎𝑛−𝑎1=11−1=10
.
In the second testcase, it is optimal to rotate the subarray starting and ending
at index 1 and rotating it by an amount of 2
.
In the fourth testcase, it is optimal to rotate the subarray starting from index
1 to index 4 and rotating it by an amount of 3 . So the answer is 8−1=7
*/

#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = -2000;
    for (int p = 1; p < n; p++) {
      int tst = a[p] - a[0];
      ans = (ans > tst) ? ans : tst;
    }
    for (int p = 0; p < n - 1; p++) {
      int tst = a[n - 1] - a[p];
      ans = (ans > tst) ? ans : tst;
    }

    for (int p = 0; p < n; p++) {
      int tst = a[(p - 1 + n) % n] - a[p];
      ans = (ans > tst) ? ans : tst;
    }

    cout << ans << endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1726/303273974
