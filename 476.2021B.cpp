/*B. Maximize Mex
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎
 of 𝑛
 positive integers and an integer 𝑥
. You can do the following two-step operation any (possibly zero) number of
times:

Choose an index 𝑖
 (1≤𝑖≤𝑛
).
Increase 𝑎𝑖
 by 𝑥
, in other words 𝑎𝑖:=𝑎𝑖+𝑥
.
Find the maximum value of the MEX
 of 𝑎
 if you perform the operations optimally.

The MEX
 (minimum excluded value) of an array is the smallest non-negative integer that
is not in the array. For example:

The MEX
 of [2,2,1]
 is 0
 because 0
 is not in the array.
The MEX
 of [3,1,0,1]
 is 2
 because 0
 and 1
 are in the array but 2
 is not.
The MEX
 of [0,3,1,2]
 is 4
 because 0
, 1
, 2
 and 3
 are in the array but 4
 is not.
Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤5000
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑥
 (1≤𝑛≤2⋅105
; 1≤𝑥≤109
) — the length of the array and the integer to be used in the operation.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤109
) — the given array.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer: the maximum MEX
 of 𝑎
 if you perform the operations optimally.

Example
InputCopy
3
6 3
0 3 2 1 5 2
6 2
1 3 4 1 0 2
4 5
2 5 10 3
OutputCopy
4
6
0
Note
In the first test case, the MEX
 of 𝑎
 is 4
 without performing any operations, which is the maximum.

In the second test case, the MEX
 of 𝑎
 is 5
 without performing any operations. If we perform two operations both with 𝑖=1
, we will have the array 𝑎=[5,3,4,1,0,2]
. Then, the MEX
 of 𝑎
 will become 6
, which is the maximum.

In the third test case, the MEX
 of 𝑎
 is 0
 without performing any operations, which is the maximum.



*/

#include <iostream>
#include <vector>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n, x;
    std::cin >> n >> x;
    std::vector<long> v(n, 0);
    for (long p = 0; p < n; p++) {
      long b;
      std::cin >> b;
      if (b < n) {
        ++v[b];
      }
    }
    long mex(n);
    for (long p = 0; p < n; p++) {
      if (!v[p]) {
        mex = p;
        break;
      }
      if (p + x < n) {
        v[p + x] += (v[p] - 1);
      }
    }
    std::cout << mex << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/2021/327531339
