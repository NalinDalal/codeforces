/*C. Asuna and the Mosquitoes
time limit per test2 seconds
memory limit per test256 megabytes
For her birthday, each of Asuna's 𝑛
 admirers gifted her a tower. The height of the tower from the 𝑖
-th admirer is equal to 𝑎𝑖
.

Asuna evaluates the beauty of the received gifts as max(𝑎1,𝑎2,…,𝑎𝑛)
. She can perform the following operation an arbitrary number of times
(possibly, zero).

Take such 1≤𝑖≠𝑗≤𝑛
 that 𝑎𝑖+𝑎𝑗
 is odd and 𝑎𝑖>0
, then decrease 𝑎𝑖
 by 1
 and increase 𝑎𝑗
 by 1
.
It is easy to see that the heights of the towers remain non-negative during the
operations. Help Asuna find the maximum possible beauty of the gifts after any
number of operations!

Input
Each test consists of several test cases. The first line of the input data
contains one integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of
the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of admirers of Asuna.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109)
 — the heights of the towers.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer: the maximum value of the beauty of
the gifts that Asuna can achieve.

Example
InputCopy
4
3
5 3 9
2
3 2
4
1 2 2 1
5
5 4 3 2 9
OutputCopy
9
5
5
21
Note
In the first test case, no pair of towers satisfies the required condition for
applying the operation, so no operations can be performed. In this case, the
answer is max(5, 3, 9)=9
.

In the second test case, the operation with 𝑖=2
 and 𝑗=1
 can be applied twice. After that, the array becomes: 𝑎 = [5, 0]
. Thus, the answer is 5.

In the third test case, the following sequence of operations can be applied:

Operation with 𝑖=1
 and 𝑗=2
.
[1, 2, 2, 1]→[0, 3, 2, 1]

Operation with 𝑖=3
 and 𝑗=2
.
[0, 3, 2, 1]→[0, 4, 1, 1]

Operation with 𝑖=3
 and 𝑗=2
.
[0, 4, 1, 1]→[0, 5, 0, 1]

max(0, 5, 0, 1) = 5
.

Therefore, the answer is 5.


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

    long cd = 0, cv = 0, mx = 0;
    long long s = 0;

    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;

      cd += (x % 2);
      cv += (1 - x % 2);
      if (x > mx)
        mx = x;
      s += x;
    }

    if (cd && cv)
      std::cout << (s - cd + 1) << '\n';
    else
      std::cout << mx << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2092/323276860
