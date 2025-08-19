/*A. Too Min Too Max
time limit per test1 second
memory limit per test256 megabytes
Given an array 𝑎
 of 𝑛
 elements, find the maximum value of the expression:

|𝑎𝑖−𝑎𝑗|+|𝑎𝑗−𝑎𝑘|+|𝑎𝑘−𝑎𝑙|+|𝑎𝑙−𝑎𝑖|

where 𝑖
, 𝑗
, 𝑘
, and 𝑙
 are four distinct indices of the array 𝑎
, with 1≤𝑖,𝑗,𝑘,𝑙≤𝑛
.

Here |𝑥|
 denotes the absolute value of 𝑥
.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤500
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (4≤𝑛≤100
) — the length of the given array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (−106≤𝑎𝑖≤106
).

Output
For each test case, print a single integer — the maximum value.

Example
InputCopy
5
4
1 1 1 1
5
1 1 2 2 3
8
5 1 3 2 -3 -1 10 3
4
3 3 1 1
4
1 2 2 -1
OutputCopy
0
6
38
8
8
Note
In the first test case, for any selection of 𝑖
, 𝑗
, 𝑘
, 𝑙
, the answer will be 0
. For example, |𝑎1−𝑎2|+|𝑎2−𝑎3|+|𝑎3−𝑎4|+|𝑎4−𝑎1|=|1−1|+|1−1|+|1−1|+|1−1|=0+0+0+0=0
.

In the second test case, for 𝑖=1
, 𝑗=3
, 𝑘=2
, and 𝑙=5
, the answer will be 6
. |𝑎1−𝑎3|+|𝑎3−𝑎2|+|𝑎2−𝑎5|+|𝑎5−𝑎1|=|1−2|+|2−1|+|1−3|+|3−1|=1+1+2+2=6
.
*/
#include <iostream>
#include <limits>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n;
    std::cin >> n;

    long mna = 1e7, mnb = 1e7;
    long mxa = -1e7, mxb = -1e7;

    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;

      if (x <= mna) {
        mnb = mna;
        mna = x;
      } else if (x < mnb) {
        mnb = x;
      }

      if (x >= mxa) {
        mxb = mxa;
        mxa = x;
      } else if (x > mxb) {
        mxb = x;
      }
    }

    std::cout << 2 * (mxa + mxb - mna - mnb) << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1934/334457430
