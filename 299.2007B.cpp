/* B. Index and Maximum Value
time limit per test1 second
memory limit per test256 megabytes
After receiving yet another integer array 𝑎1,𝑎2,…,𝑎𝑛
 at her birthday party, Index decides to perform some operations on it.

Formally, there are 𝑚
 operations that she is going to perform in order. Each of them belongs to one
of the two types:

+ 𝚕 𝚛
. Given two integers 𝑙
 and 𝑟
, for all 1≤𝑖≤𝑛
 such that 𝑙≤𝑎𝑖≤𝑟
, set 𝑎𝑖:=𝑎𝑖+1
.
- 𝚕 𝚛
. Given two integers 𝑙
 and 𝑟
, for all 1≤𝑖≤𝑛
 such that 𝑙≤𝑎𝑖≤𝑟
, set 𝑎𝑖:=𝑎𝑖−1
.
For example, if the initial array 𝑎=[7,1,3,4,3]
, after performing the operation + 2 4
, the array 𝑎=[7,1,4,5,4]
. Then, after performing the operation - 1 10
, the array 𝑎=[6,0,3,4,3]
.

Index is curious about the maximum value in the array 𝑎
. Please help her find it after each of the 𝑚
 operations.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤2⋅104 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛≤105
, 1≤𝑚≤105
) — the length of the array and the number of operations.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the initial array 𝑎
.

Then 𝑚
 lines follow, each line corresponds to the operation, in the following format:
𝚌 𝚕 𝚛 (𝑐∈{+,-} , 𝑙 and 𝑟 are integers, 1≤𝑙≤𝑟≤109 ) — the description of the
operation.

Note that the elements 𝑎𝑖
 may not satisfy 1≤𝑎𝑖≤109
 after some operations, as it is shown in the example.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
, and the sum of 𝑚
 over all test cases does not exceed 105
.

Output
For each test case, output one single line containing 𝑚
 integers, with the 𝑖
-th of them describing the maximum value of the array after the 𝑖
-th operation.

Example
InputCopy
5
5 5
1 2 3 2 1
+ 1 3
- 2 3
+ 1 2
+ 2 4
- 6 8
5 5
1 3 3 4 5
+ 1 4
+ 2 3
- 4 5
- 3 3
- 2 6
5 5
1 1 1 1 1
+ 2 3
- 4 5
+ 1 6
- 2 5
+ 1 8
1 1
1
- 1 1
1 1
1000000000
+ 1000000000 1000000000
OutputCopy
4 4 4 5 5
5 5 4 4 3
1 1 2 1 2
0
1000000001
Note
In the first test case, the process of the operations is listed below:

After the first operation, the array becomes equal [2,3,4,3,2]
. The maximum value is 4
.
After the second operation, the array becomes equal [1,2,4,2,1]
. The maximum value is 4
.
After the third operation, the array becomes equal [2,3,4,3,2]
. The maximum value is 4
.
After the fourth operation, the array becomes equal [3,4,5,4,3]
. The maximum value is 5
.
After the fifth operation, the array becomes equal [3,4,5,4,3]
. The maximum value is 5
.
In the second test case, the process of the operations is listed below:

After the first operation, the array becomes equal [2,4,4,5,5]
. The maximum value is 5
.
After the second operation, the array becomes equal [3,4,4,5,5]
. The maximum value is 5
.
After the third operation, the array becomes equal [3,3,3,4,4]
. The maximum value is 4
.
After the fourth operation, the array becomes equal [2,2,2,4,4]
. The maximum value is 4
.
After the fifth operation, the array becomes equal [1,1,1,3,3]
. The maximum value is 3
.


*/
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n, m;
    std::cin >> n >> m;

    long x = 0;
    for (long i = 0; i < n; ++i) {
      long a;
      std::cin >> a;
      if (a > x) {
        x = a;
      }
    }

    for (long i = 0; i < m; ++i) {
      char op;
      long l, r;
      std::cin >> op >> l >> r;

      if (l <= x && x <= r) {
        if (op == '+') {
          x += 1;
        } else if (op == '-') {
          x -= 1;
        }
      }

      std::cout << x << " ";
    }

    std::cout << '\n';
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2007/316046688
