/*C1. Shohag Loves XOR (Easy Version)
time limit per test2 seconds
memory limit per test256 megabytes
This is the easy version of the problem. The differences between the two
versions are highlighted in bold. You can only make hacks if both versions of
the problem are solved.

Shohag has two integers 𝑥
 and 𝑚
. Help him count the number of integers 1≤𝑦≤𝑚
 such that 𝐱≠𝐲
 and 𝑥⊕𝑦
 is a divisor∗
 of either 𝑥
, 𝑦
, or both. Here ⊕
 is the bitwise XOR operator.

∗
The number 𝑏
 is a divisor of the number 𝑎
 if there exists an integer 𝑐
 such that 𝑎=𝑏⋅𝑐
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first and only line of each test case contains two space-separated integers
𝑥 and 𝑚 (1≤𝑥≤106 , 1≤𝑚≤1018
).

It is guaranteed that the sum of 𝑥
 over all test cases does not exceed 107
.

Output
For each test case, print a single integer — the number of suitable 𝑦
.

Example
InputCopy
5
6 9
5 7
2 3
6 4
4 1
OutputCopy
3
2
1
1
0
Note
In the first test case, for 𝑥=6
, there are 3
 valid values for 𝑦
 among the integers from 1
 to 𝑚=9
, and they are 4
, 5
, and 7
.

𝑦=4
 is valid because 𝑥⊕𝑦=6⊕4=2
 and 2
 is a divisor of both 𝑥=6
 and 𝑦=4
.
𝑦=5
 is valid because 𝑥⊕𝑦=6⊕5=3
 and 3
 is a divisor of 𝑥=6
.
𝑦=7
 is valid because 𝑥⊕𝑦=6⊕7=1
 and 1
 is a divisor of both 𝑥=6
 and 𝑦=7
.
In the second test case, for 𝑥=5
, there are 2
 valid values for 𝑦
 among the integers from 1
 to 𝑚=7
, and they are 4
 and 6
.

𝑦=4
 is valid because 𝑥⊕𝑦=5⊕4=1
 and 1
 is a divisor of both 𝑥=5
 and 𝑦=4
.
𝑦=6
 is valid because 𝑥⊕𝑦=5⊕6=3
 and 3
 is a divisor of 𝑦=6
.


*/
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long x, m;
    std::cin >> x >> m;
    long cnt = 0;
    for (long p = 1; p < x; ++p) {
      long y = x ^ p;
      if (y > m)
        continue;
      cnt += ((x % p == 0) || (y % p == 0));
    }
    std::cout << cnt << "\n";
  }

  return 0;
}
