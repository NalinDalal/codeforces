/*C. Nene's Magical Matrix
time limit per test2 seconds
memory limit per test256 megabytes
The magical girl Nene has an 𝑛×𝑛
 matrix 𝑎
 filled with zeroes. The 𝑗
-th element of the 𝑖
-th row of matrix 𝑎
 is denoted as 𝑎𝑖,𝑗
.

She can perform operations of the following two types with this matrix:

Type 1
 operation: choose an integer 𝑖
 between 1
 and 𝑛
 and a permutation 𝑝1,𝑝2,…,𝑝𝑛
 of integers from 1
 to 𝑛
. Assign 𝑎𝑖,𝑗:=𝑝𝑗
 for all 1≤𝑗≤𝑛
 simultaneously.
Type 2
 operation: choose an integer 𝑖
 between 1
 and 𝑛
 and a permutation 𝑝1,𝑝2,…,𝑝𝑛
 of integers from 1
 to 𝑛
. Assign 𝑎𝑗,𝑖:=𝑝𝑗
 for all 1≤𝑗≤𝑛
 simultaneously.
Nene wants to maximize the sum of all the numbers in the matrix ∑𝑖=1𝑛∑𝑗=1𝑛𝑎𝑖,𝑗
. She asks you to find the way to perform the operations so that this sum is
maximized. As she doesn't want to make too many operations, you should provide a
solution with no more than 2𝑛 operations.

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
test cases 𝑡 (1≤𝑡≤500
). The description of test cases follows.

The only line of each test case contains a single integer 𝑛
 (1≤𝑛≤500
) — the size of the matrix 𝑎
.

It is guaranteed that the sum of 𝑛2
 over all test cases does not exceed 5⋅105
.

Output
For each test case, in the first line output two integers 𝑠
 and 𝑚
 (0≤𝑚≤2𝑛
) — the maximum sum of the numbers in the matrix and the number of operations in
your solution.

In the 𝑘
-th of the next 𝑚
 lines output the description of the 𝑘
-th operation:

an integer 𝑐
 (𝑐∈{1,2}
) — the type of the 𝑘
-th operation;
an integer 𝑖
 (1≤𝑖≤𝑛
) — the row or the column the 𝑘
-th operation is applied to;
a permutation 𝑝1,𝑝2,…,𝑝𝑛
 of integers from 1
 to 𝑛
 — the permutation used in the 𝑘
-th operation.
Note that you don't need to minimize the number of operations used, you only
should use no more than 2𝑛 operations. It can be shown that the maximum possible
sum can always be obtained in no more than 2𝑛 operations.

Example
InputCopy
2
1
2
OutputCopy
1 1
1 1 1
7 3
1 1 1 2
1 2 1 2
2 1 1 2
Note
In the first test case, the maximum sum 𝑠=1
 can be obtained in 1
 operation by setting 𝑎1,1:=1
.

In the second test case, the maximum sum 𝑠=7
 can be obtained in 3
 operations as follows:


It can be shown that it is impossible to make the sum of the numbers in the
matrix larger than 7
*/

/*We start with an n×n zero matrix.

Two allowed operations:

- Pick a row i and fill it with a permutation of [1..n].

- Pick a column i and fill it with a permutation of [1..n].

Each operation rewrites the whole row/column at once.

Goal: maximize the total sum of matrix entries.

Allowed ≤ 2n operations.
*/

/*logic:
 Fill all rows with the same permutation [1,2,…,n].
→ This gives base sum n*n*(n+1)/2

for one column-> [n,n-1,...,1]
accounts to n(n-1)/2

total ans= n*n*(n+1)/2+ n(n-1)/2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long T;
  if (!(cin >> T))
    return 0;
  while (T--) {
    long long n;
    cin >> n;

    // Original formula preserved:
    // prints sum and number of operations (2*n)
    long long sum = n * (n + 1) * (2 * n + 1) / 3 - n * (n + 1) / 2;
    cout << sum << " " << 2 * n << '\n';

    // For j = n..1, print:
    // type 1, index j, permutation [1..n]
    // type 2, index j, permutation [1..n]
    for (long long j = n; j >= 1; --j) {
      cout << 1 << " " << j;
      for (long long i = 1; i <= n; ++i)
        cout << " " << i;
      cout << '\n';

      cout << 2 << " " << j;
      for (long long i = 1; i <= n; ++i)
        cout << " " << i;
      cout << '\n';
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1956/336347757
