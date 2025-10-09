/*B. Make It Permutation
time limit per test1 second
memory limit per test256 megabytes
There is a matrix 𝐴
 of size 𝑛×𝑛
 where 𝐴𝑖,𝑗=𝑗
 for all 1≤𝑖,𝑗≤𝑛
.

In one operation, you can select a row and reverse any subarray∗
 in it.

Find a sequence of at most 2𝑛
 operations such that every column will contain a permutation†
 of length 𝑛
.

It can be proven that the construction is always possible. If there are multiple
solutions, output any of them.

∗
An array 𝑎
 is a subarray of an array 𝑏
 if 𝑎
 can be obtained from 𝑏
 by deleting zero or more elements from the beginning and zero or more elements
from the end.

†
A permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100
). The description of the test cases follows.

The first line of each test case contains one integer 𝑛
 (3≤𝑛≤5000
) — denoting the number of rows and columns in the matrix.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 5000
.

Output
For each test case, on the first line, print an integer 𝑘
 (0≤𝑘≤2𝑛)
, the number of operations you wish to perform. On the next lines, you should
print the operations.

To print an operation, use the format "𝑖𝑙𝑟
" (1≤𝑙≤𝑟≤𝑛
 and 1≤𝑖≤𝑛
) which reverses the subarray 𝐴𝑖,𝑙
, 𝐴𝑖,𝑙+1
, …
, 𝐴𝑖,𝑟
.

Example
InputCopy
2
3
4
OutputCopy
4
2 1 3
2 2 3
3 1 2
3 2 3
5
2 1 4
3 1 3
3 2 4
4 3 4
4 1 2
Note
In the first test case, the following operations are a valid solution:
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    cout << (2 * n - 1) << '\n';

    for (long p = 1; p < n; ++p) {
      cout << p << " 1 " << p << '\n';
      cout << p << " " << (p + 1) << " " << n << '\n';
    }

    cout << n << " 1 " << n << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2118/342675185
